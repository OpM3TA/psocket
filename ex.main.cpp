#include "tcpsocket.h"


using namespace std;


int main()
{
	tcpsocket *sock = new tcpsocket();
	sock->init();
	int testsock = sock->pconnect("192.168.1.8", "1234");
	if (testsock == 0) {
			sock->psend("Hello, World!\n");
			char *msg = sock->precv(50); // Would recv 50 bytes of data that the server sends.
			printf(msg);
			delete[] msg; // pew pew
	}
	delete sock;
	getchar();
}
