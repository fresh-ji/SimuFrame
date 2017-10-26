
#include "managerI.h"

using namespace std;
using namespace Ice;
using namespace Demo;

int main(int argc, char* argv[]) {
	CommunicatorPtr ic;
	try {
		ic = initialize(argc,argv);

		ObjectAdapterPtr Adapter = ic->createObjectAdapterWithEndpoints("Adapter", "$EVENTMANAGERLOCATION$");

		eventManagerPtr Ptr = new eventManagerI;
		
		Adapter->add(Ptr, ic->stringToIdentity("sentinel"));

		Adapter->activate();

		//本地初始化列表
		Ptr->initList();

		//发送代理
		eventManagerPrx proxy = eventManagerPrx::uncheckedCast(Adapter->createProxy(ic->stringToIdentity("sentinel")));
		Ptr->initProxy(proxy);

		cout << "Event Manager is Ready!!!" << endl;

		ic->waitForShutdown();
	} catch (const Ice::Exception& ex) {
		cerr << ex << endl;
	} catch (const char* msg) {
		cerr << msg << endl;
	}
	if (ic) {
		ic->destroy();
	}
	return 1;
}