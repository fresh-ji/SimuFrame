#include "workerI.h"
using namespace std;
using namespace Demo;
using namespace Ice;

int main(int argc, char* argv[]) {
	Ice::CommunicatorPtr ic;
	try {
		ic = Ice::initialize(argc,argv);

		Ice::ObjectAdapterPtr insBAdapter = ic->createObjectAdapterWithEndpoints("localAdapter", "tcp -h 127.0.0.1 -p 12340");

		insBPtr insBP = new insBI;
		Ice::ObjectPrx insBProxy = insBAdapter->addWithUUID(insBP);

		Ice::ObjectPrx insBObj = ic->stringToProxy("LVCIS/TopicManager:tcp -h 127.0.0.1 -p 12337");

		IceStorm::TopicManagerPrx topicManager = IceStorm::TopicManagerPrx::checkedCast(insBObj);
		try{
			IceStorm::QoS qos;
			topicManager->retrieve("evOrder")->subscribe(qos, insBProxy);
			
			topicManager->retrieve("evFromA")->subscribe(qos, insBProxy);

		} catch (const IceStorm::NoSuchTopic&) {
			cerr << "Error! No Topic Found!" << endl;
		}

		insBAdapter->activate();
		cout << "insB is ready!!" << endl;
		ic->waitForShutdown();
	} catch (const Ice::Exception& ex) {
		cerr << ex << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
	if (ic) {
		ic->destroy();
	}
	return 0;
}