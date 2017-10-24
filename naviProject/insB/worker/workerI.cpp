
#include "workerI.h"

using namespace std;
using namespace Ice;
using namespace Demo;

void insBI::shutdown(const Current& c) {
	cout << "closing..." << endl;
	try {
		c.adapter->getCommunicator()->shutdown();
	} catch(const Exception& ex) {
		cout << ex << endl;
	}
}

void insBI::initEvent(const eventManagerPrx& proxy, const Current& c) {
	eventProxy = proxy;
	cout << "Acquire Event Proxy!!!" << endl;
}


void insBI::initTime(const timeManagerPrx& proxy, double startTime, double step, const Current& c) {
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
	timeProxy->confirmTime("insB");
}

void insBI::HANDLEevent(const event& ev, const Current& c) {
	FEL.push_back(ev);
}

bool insBI::comp(event ev1, event ev2) {
	return ev1.time < ev2.time;
}

void insBI::HANDLEtime(double currentTime, const Current& c) {
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
		
		if("evFromA" == FEL[0].name) {
			HANDLEevFromA(FEL[0]);
		}

		FEL.erase(FEL.begin());
	}
	timeProxy->confirmTime("insB");
}

void insBI::tick() {
	event ev0;
	ev0.name = "tick";
	//Todo:handle tick
	ev0.time = currentTime + step;
	FEL.push_back(ev0);
	if(((int)currentTime)%10 == 6) {
		event ev1;
		ev1.name = "evFromB";
		ev1.time = currentTime + step;
		eventProxy->SENDevent(ev1);
	}
	//End
}

void insBI::HANDLEevFromA(event ev) {
	cout << "B is handling A at " << ev.time << endl;
}

//Todo:user-define functions

//End