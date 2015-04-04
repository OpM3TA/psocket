#include "tcpsocket.h"
#include <fstream>

using namespace std;


int main()
{

	tcpsocket *sock = new tcpsocket();
	sock->init();
	int testsock = sock->connect_("192.168.1.8", "80");
	if (testsock == 0) {
		sock->send_("Hello");
		char *msg = sock->recv_(1050);
	

	}
	delete sock;
	getchar();
}
