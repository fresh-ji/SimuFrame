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

class timeManagerI : public timeManager {
public:
	virtual void initList(const Current&);
	virtual void initProxy(const timeManagerPrx& proxy, double startTime, double step, const Current&);
	virtual bool checkList(const Current&);
	virtual void confirmTime(const string& modelName, const Current&);
	virtual void SENDtime(double currentTime, const Current&);
	virtual void shutdown(const Current&);
	
	struct list {
		string modelName;
		bool isConfirm;
	};
	vector<list>Vec;
private:
};


