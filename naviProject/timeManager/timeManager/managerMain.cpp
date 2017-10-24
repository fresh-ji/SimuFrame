
#include "managerI.h"

using namespace std;
using namespace Ice;
using namespace Demo;

int main(int argc, char* argv[]) {
	CommunicatorPtr ic;
	try {
		ic = initialize(argc,argv);

		ObjectAdapterPtr Adapter = ic->createObjectAdapterWithEndpoints("Adapter", "tcp -h 127.0.0.1 -p 12338");

		timeManagerPtr Ptr = new timeManagerI;
		
		Adapter->add(Ptr, ic->stringToIdentity("sentinel"));

		Adapter->activate();

		//本地初始化列表
		Ptr->initList();

		//发送代理
		double currentTime = 0.0;
		double step = 0.1;
		timeManagerPrx proxy = timeManagerPrx::uncheckedCast(Adapter->createProxy(ic->stringToIdentity("sentinel")));
		Ptr->initProxy(proxy, currentTime, step);

		while(!Ptr->checkList()) {
			continue;
		}

		while(true) {
			currentTime += step;
			
			Ptr->initList();
			//Ptr->HANDLEevOrder(currentTime);
			while(!Ptr->checkList()) {
				continue;
			}

			cout << "now step is :  " << currentTime << endl;
		}

		ic->waitForShutdown();
	} catch (const Ice::Exception& ex) {
		cerr << ex << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
	if (ic) {
		ic->destroy();
	}
	return 0;
}