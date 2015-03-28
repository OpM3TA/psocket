#include "tcpsocket.h"


using namespace std;


int main()
{
	tcpsocket *s = new tcpsocket();
	char * msg = s->pconnect("192.168.1.8", "5656").ErrMsg; // Try to connect & return status

	if (msg== OK){
		s->psend("Hello, friend\n");
		char* data = s->precv(50);
		printf("%s", data);
	}
	else if (msg == CreateSockErr)
	{
		printf("Could not create socket. -> socket()");
	}
	else if (msg == ConnectErr)
	{
		printf("Could not connect to the host -> connect()");
	}
	getchar();
	
}
