#include "tcpsocket.h"


using namespace std;


int main()
{
	tcpsocket *sock = new tcpsocket();
	sock->init();
	int r = sock->pconnect("192.168.1.8", "1234");
	printf("%d", r);
	getchar();
}
