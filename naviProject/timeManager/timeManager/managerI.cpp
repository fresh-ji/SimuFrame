
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
	Vec.resize(2);
	Vec[0].modelName = "insA";
	Vec[0].isConfirm = false;
	Vec[1].modelName = "insB";
	Vec[1].isConfirm = false;
}

void timeManagerI::initProxy(const timeManagerPrx& proxy, double startTime, double step, const Current& c) {
	Ice::CommunicatorPtr ic;
	try {
		int argc = 0;
		char* argv[1];
		ic = Ice::initialize(argc, argv);
		insAPrx insAP = insAPrx::checkedCast(ic->stringToProxy("sentinel:tcp -h 127.0.0.1 -p 12339"));
		insAP->initTime(proxy, startTime, step);
		insBPrx insBP = insBPrx::checkedCast(ic->stringToProxy("sentinel:tcp -h 127.0.0.1 -p 12340"));
		insBP->initTime(proxy, startTime, step);
		ic->destroy();
	} catch (const Ice::Exception& ex) {
		cerr << ex << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
}

bool timeManagerI::checkList(const Current& c) {
	for(int i=0;i<2;++i){
		if(false == Vec[i].isConfirm)
			return false;
	}
	return true;
}

void timeManagerI::confirmTime(const string& modelName, const Current& c) {
	for(int i=0;i<2;++i){
		if(modelName == Vec[i].modelName) {
			Vec[i].isConfirm = true;
			break;
		}
	}
}

void timeManagerI::SENDevOrder(double currentTime, const Current& c) {
	Ice::CommunicatorPtr ic;
	try {
		int argc = 0;
		char* argv[1];
		ic = Ice::initialize(argc, argv);
		insAPrx insAP = insAPrx::checkedCast(ic->stringToProxy("sentinel:tcp -h 127.0.0.1 -p 12339"));
		insAP-
		insBPrx insBP = insBPrx::checkedCast(ic->stringToProxy("sentinel:tcp -h 127.0.0.1 -p 12340"));
		insBP->initTime(proxy, startTime, step);
		ic->destroy();
	} catch (const Ice::Exception& ex) {
		cerr << ex << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
}