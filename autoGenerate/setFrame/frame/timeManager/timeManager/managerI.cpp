
#include "managerI.h"

using namespace std;
using namespace Ice;
using namespace Demo;

void timeManagerI::shutdown(const Current& c) {
	cout << "closing..." << endl;
	try {
		c.adapter->getCommunicator()->shutdown();
	} catch(const Exception& ex) {
		cout << ex << endl;
	}
}

void timeManagerI::initList(const Current& c) {
	Vec.resize($MODELNUMBER$);
	$INITIALLISTLOOP$
}

void timeManagerI::initProxy(const timeManagerPrx& proxy, double startTime, double step, const Current& c) {
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

bool timeManagerI::checkList(const Current& c) {
	for(int i=0;i<$MODELNUMBER$;++i){
		if(false == Vec[i].isConfirm)
			return false;
	}
	return true;
}

void timeManagerI::confirmTime(const string& modelName, const Current& c) {
	for(int i=0;i<$MODELNUMBER$;++i){
		if(modelName == Vec[i].modelName) {
			Vec[i].isConfirm = true;
			break;
		}
	}
}

void timeManagerI::SENDtime(double currentTime, const Current& c) {
	Ice::CommunicatorPtr ic;
	try {
		int argc = 0;
		char* argv[1];
		ic = Ice::initialize(argc, argv);
		$SENDTIMELOOP$
		ic->destroy();
	} catch (const Ice::Exception& ex) {
		//cerr << ex << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
}