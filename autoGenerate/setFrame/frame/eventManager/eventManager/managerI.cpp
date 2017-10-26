
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
	Vec.resize($MODELNUMBER$);
	$INITIALLISTLOOP$
}

void eventManagerI::initProxy(const eventManagerPrx& proxy, const Current& c) {
	Ice::CommunicatorPtr ic;
	try {
		int argc = 0;
		char* argv[1];
		ic = Ice::initialize(argc, argv);
		$INITIALPROXYLOOP$
		ic->destroy();
	} catch (const Ice::Exception& ex) {
		//cerr << ex << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
}

void eventManagerI::SENDevent(const event& ev, const Current& c) {
	//cout << "event transferring:" << ev.name << "   time to execute:" << ev.time << endl;

	Ice::CommunicatorPtr ic;
	try {
		int argc = 0;
		char* argv[1];
		ic = Ice::initialize(argc, argv);
		$SENDEVENTLOOP$
		ic->destroy();
	} catch (const Ice::Exception& ex) {
		//cerr << ex << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
}
