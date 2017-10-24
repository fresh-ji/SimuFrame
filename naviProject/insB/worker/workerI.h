//Todo:additional includes

//End

#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>
#include <string>
#include <iostream>
#include <vector>
#include "sliceDef.h"

using namespace std;
using namespace Ice;
using namespace Demo;

class insBI : public insB {
public:
	virtual void initEvent(const eventManagerPrx& proxy, const Current&);
	virtual void initTime(const timeManagerPrx& proxy, double startTime, double step, const Current&);
	virtual void HANDLEevent(const event& ev, const Current&);
	virtual void HANDLEtime(double currentTime, const Current&);
	virtual void shutdown(const Current&);
private:
	eventManagerPrx eventProxy;
	timeManagerPrx timeProxy;
	double currentTime;
	double step;

	//实体信息
	struct entity {
		//Todo:entity information

		//end
	};
	vector<entity>EL;
	int currentNumber;
	int inventory;

	//事件信息
	vector<event>FEL;
	static bool comp(event, event);
	void tick();
	void HANDLEevFromA(event ev);

	//Todo:user-define functions
	
	//End
};
