#include "workerI.h"
using namespace std;
using namespace Demo;
using namespace Ice;

int main(int argc, char* argv[]) {
	Ice::CommunicatorPtr ic;
	try {
		ic = Ice::initialize(argc,argv);

		Ice::ObjectAdapterPtr insAAdapter = ic->createObjectAdapterWithEndpoints("localAdapter", "tcp -h 127.0.0.1 -p 12339");

		insAPtr insAP = new insAI;
		Ice::ObjectPrx insAProxy = insAAdapter->addWithUUID(insAP);

		Ice::ObjectPrx insAObj = ic->stringToProxy("LVCIS/TopicManager:tcp -h 127.0.0.1 -p 12337");

		IceStorm::TopicManagerPrx topicManager = IceStorm::TopicManagerPrx::checkedCast(insAObj);
		try{
			IceStorm::QoS qos;
			topicManager->retrieve("evOrder")->subscribe(qos, insAProxy);
			
			topicManager->retrieve("evFromB")->subscribe(qos, insAProxy);

		} catch (const IceStorm::NoSuchTopic&) {
			cerr << "Error! No Topic Found!" << endl;
		}

		insAAdapter->activate();
		cout << "insA is ready!!" << endl;
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