
#include "workerI.h"

using namespace std;
using namespace Demo;
using namespace Ice;

int main(int argc, char* argv[]) {
	Ice::CommunicatorPtr ic;
	try {
		ic = Ice::initialize(argc,argv);

		ObjectAdapterPtr Adapter = ic->createObjectAdapterWithEndpoints("Adapter", "$MODELLOCATION$");

		$MODELNAME$Ptr Ptr = new $MODELNAME$I;

		Adapter->add(Ptr, ic->stringToIdentity("sentinel"));
		
		Adapter->activate();

		cout << "$MODELNAME$ is ready!!" << endl;

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