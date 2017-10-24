#include "workerI.h"
using namespace std;
using namespace Ice;
using namespace Demo;

void insAI::shutdown(const Current& c) {
	cout << "closing..." << endl;
	try {
		c.adapter->getCommunicator()->shutdown();
	} catch(const Exception& ex) {
		cout << ex << endl;
	}
}

bool insAI::comp(event ev1, event ev2) {
	return ev1.time < ev2.time;
}

void insAI::publishEvent(event ev) {
	int argc = 0;
	char* argv[1];
	ic1 = initialize(argc, argv);
	ObjectPrx obj = ic1->stringToProxy("LVCIS/TopicManager:tcp -h 127.0.0.1 -p 12337");
	IceStorm::TopicManagerPrx topicManger = IceStorm::TopicManagerPrx::checkedCast(obj);
	IceStorm::TopicPrx topic = topicManger->retrieve(ev.name);
	ObjectPrx pub = topic->getPublisher()->ice_oneway();
	managerPrx Prx_manager = managerPrx::uncheckedCast(pub);
	Prx_manager->HANDLEevent(ev);
	ic1->destroy();
}

void insAI::initWorker(const managerPrx& proxy, double startTime, double step, const Current& c) {
	this->proxy = proxy;
	this->currentTime = startTime;
	this->step = step;
	this->currentNumber = 0;
	event ev0;
	ev0.time = 99999.0;
	FEL.push_back(ev0);
	//Todo:entity initial

	//End
	tick();
	proxy->confirmTime("insA");
}

void insAI::HANDLEevOrder(double currentTime, const Current& c) {
	sort(FEL.begin(), FEL.end(), comp);
	this->currentTime = currentTime;
	/********* timeMode = unconfirm */
	/*

	/********************************/
	
	/********** timeMode = confirm **/
	
	while((currentTime-FEL[0].time) > 10e-5 ) {
		//cout << "process lag event£º" << FEL[0].name << "  delay time£º" << currentTime-FEL[0].time << endl;
		//Todo:lag event

		//End
		FEL.erase(FEL.begin());
	}
	while(fabs(FEL[0].time-currentTime) < 10e-5) {
		//cout << "process event£º" << FEL[0].name << "  coming time£º" << currentTime << endl;
		if("tick" == FEL[0].name) {
			tick();
		}
		
		if("evFromB" == FEL[0].name) {
			HANDLEevFromB(FEL[0]);
		}

		FEL.erase(FEL.begin());
	}
	proxy->confirmTime("insA");
	/********************************/
}

void insAI::HANDLEevent(const event& ev, const Current& c) {
	FEL.push_back(ev);
}

void insAI::tick() {
	event ev0;
	ev0.name = "tick";
	//Todo:handle tick

	//End
}

void insAI::HANDLEevFromB(event ev) {

}

//End

//Todo:user-define functions

//End