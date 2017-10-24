#pragma once

module Demo {

struct position {double px;double py;double pz;};

sequence<position> seqPoint;

sequence<int> seqInteger;

sequence<string> seqString;

struct event {string name;double time;seqString seqStr;seqInteger seqInt;seqPoint seqPt;};

	interface eventManager {
		void initList();
		void initProxy(eventManager* proxy);
		void SENDevent(event ev);
		void shutdown();
	};

	interface timeManager {
		void initList();
		void initProxy(timeManager* proxy, double startTime, double step);
		bool checkList();
		void confirmTime(string modelName);
		void SENDtime(double currentTime);
		void shutdown();
	};

	interface insA {
		void initEvent(eventManager* proxy);
		void initTime(timeManager* proxy, double startTime, double step);
		void HANDLEevent(event ev);
		void HANDLEtime(double currentTime);
		void shutdown();
	};

	interface insB {
		void initEvent(eventManager* proxy);
		void initTime(timeManager* proxy, double startTime, double step);
		void HANDLEevent(event ev);
		void HANDLEtime(double currentTime);
		void shutdown();
	};

};