
#include "managerI.h"

using namespace std;
using namespace Ice;
using namespace Demo;

void eventManagerI::shutdown(const Current& c) {
	cout << "closing..." << endl;
	try {
		c.adapter->getCommunicator()->shutdown();
	} catch(const Exception& ex) {
		cout << ex << endl;
	}
}

void eventManagerI::initList(const Current& c) {
	Vec.resize(2);
	Vec[0].modelName = "insA";
	Vec[0].location = "sentinel:tcp -h 127.0.0.1 -p 12339";
	Vec[1].modelName = "insB";
	Vec[1].location = "sentinel:tcp -h 127.0.0.1 -p 12340";
}

void eventManagerI::initProxy(const eventManagerPrx& proxy, const Current& c) {
	Ice::CommunicatorPtr ic;
	try {
		int argc = 0;
		char* argv[1];
		ic = Ice::initialize(argc, argv);
		insAPrx insAP = insAPrx::checkedCast(ic->stringToProxy(Vec[0].location));
		insAP->initEvent(proxy);
		insBPrx insBP = insBPrx::checkedCast(ic->stringToProxy(Vec[1].location));
		insBP->initEvent(proxy);
		ic->destroy();
	} catch (const Ice::Exception& ex) {
		cerr << ex << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
}

void eventManagerI::HANDLEevent(const event& ev, const Current& c) {
	cout << "event transferring:" << ev.name << "   time to execute:" << ev.time << endl;
}
