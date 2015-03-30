#include "tcpsocket.h"

using namespace std;

int main()
{
	tcpsocket *sock = new tcpsocket();
	sock->init();
	int res = sock->pconnect("192.168.1.8", "1234");
	if (res== 0) {
			sock->psend("Hello, World!\n");
	}
	getchar();
}
