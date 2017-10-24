
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

void insAI::initEvent(const eventManagerPrx& proxy, const Current& c) {
	eventProxy = proxy;
	cout << "Acquire Event Proxy!!!" << endl;
}


void insAI::initTime(const timeManagerPrx& proxy, double startTime, double step, const Current& c) {
	currentTime = startTime;
	this->step = step;
	timeProxy = proxy;
	cout << "Acquire Time Proxy!!!" << endl;
	//其他初始化
	currentNumber = 0;
	event ev0;
	ev0.time = 99999.0;
	FEL.push_back(ev0);
	//Todo:entity initial

	//End
	tick();
	timeProxy->confirmTime("insA");
}

void insAI::HANDLEevent(const event& ev, const Current& c) {
	FEL.push_back(ev);
}

bool insAI::comp(event ev1, event ev2) {
	return ev1.time < ev2.time;
}

void insAI::HANDLEtime(double currentTime, const Current& c) {
	sort(FEL.begin(), FEL.end(), comp);
	this->currentTime = currentTime;
	
	while((currentTime-FEL[0].time) > 10e-5 ) {
		//cout << "process lag event：" << FEL[0].name << "  delay time：" << currentTime-FEL[0].time << endl;
		//Todo:lag event

		//End
		FEL.erase(FEL.begin());
	}
	while(fabs(FEL[0].time-currentTime) < 10e-5) {
		//cout << "process event：" << FEL[0].name << "  coming time：" << currentTime << endl;
		if("tick" == FEL[0].name) {
			tick();
		}
		
		if("evFromB" == FEL[0].name) {
			HANDLEevFromB(FEL[0]);
		}

		FEL.erase(FEL.begin());
	}
	timeProxy->confirmTime("insA");
}

void insAI::tick() {
	event ev0;
	ev0.name = "tick";
	//Todo:handle tick

	//End
}

void insAI::HANDLEevFromB(event ev) {
	cout << "A is handling B at " << ev.time << endl;
	event ev0;
	ev0.name = "evFromA";
	ev0.time = currentTime + step;
	eventProxy->SENDevent(ev0);
}

//Todo:user-define functions

//End