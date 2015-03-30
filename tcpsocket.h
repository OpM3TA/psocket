#pragma once
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

// Lets link some libs
#pragma comment (lib, "Ws2_32.lib") // so hawt
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

// Not in use right now.
// If it errors it returns the 'id' of the error from WSAGetLastError()
#define OK 0
#define ConnectErr -1
#define CreateSockErr -2
#define GetAddrInfoErr -3



class tcpsocket{

private:
	int pResult;
	struct addrinfo *result = NULL, *ptr = NULL, hints;
	SOCKET ConnectSocket;
	//struct ReturnStatus { char* ErrMsg; int status; };

public:
	tcpsocket();

	int pconnect(char* IPAddress, char* Port);
	int psend(char *);
	void pclose();
	char* precv(int bytes);
	


};

