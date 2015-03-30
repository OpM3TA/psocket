#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>


// Lets link some libs
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")



class tcpsocket{

private:
	int pResult;
	struct addrinfo *result = NULL, *ptr = NULL, hints;
	SOCKET ConnectSocket;
	//struct ReturnStatus { char* ErrMsg; int status; };

public:
	//tcpsocket();

	int init();
	int pconnect(char* IPAddress, char* Port);
	int psend(char *);
	void pclose();
	char* precv(int bytes);
	


};

