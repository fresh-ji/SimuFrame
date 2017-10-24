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

class eventManagerI : public eventManager {
public:
	virtual void initList(const Current&);
	virtual void initProxy(const eventManagerPrx& proxy, const Current&);
	virtual void HANDLEevent(const event& ev, const Current&);
	virtual void shutdown(const Current&);
	
	struct list {
		string modelName;
		string location;
	};
	vector<list>Vec;
private:
};


