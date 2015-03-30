#include "tcpsocket.h"


using namespace std;


int main()
{
	tcpsocket *sock = new tcpsocket();
	sock->init();
	int testsock = sock->pconnect("192.168.1.8", "1234");
	if (testsock == 0) {
			sock->psend("Hello, World!\n");
	}
	delete sock;
	getchar();
}
