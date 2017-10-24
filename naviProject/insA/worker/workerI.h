//Todo:additional includes

//End
#include <Ice/Ice.h>
#include <IceStorm/IceStorm.h>
#include <IceUtil/IceUtil.h>
#include <string>
#include <iostream>
#include <vector>
#include "sliceDef.h"

using namespace std;
using namespace Ice;
using namespace Demo;

class insAI : public insA {
public:
	virtual void initWorker(const managerPrx& proxy, double startTime, double step, const Current&);
	virtual void HANDLEevOrder(double currentTime, const Current&);
	virtual void HANDLEevent(const event& ev, const Current&);
	virtual void shutdown(const Current&);
private:
	managerPrx proxy;
	double currentTime;
	double step;
	int currentNumber;
	int inventory;
	struct entity {
		//Todo:entity information

		//end
	};
	vector<entity>EL;
	vector<event>FEL;

	CommunicatorPtr ic1;
	static bool comp(event, event);
	void publishEvent(event);
	void tick();

	
	void HANDLEevFromB(event ev);


	//Todo:user-define functions
	
	//End
};
