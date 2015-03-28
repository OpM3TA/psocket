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

#define ConnectErr "Error on connect()"
#define CreateSockErr "Error on socket()"
#define GetAddrInfoErr "getaddrinfo failed"
#define OK "OK"


class tcpsocket{

private:
	int iResult;
	struct addrinfo *result = NULL, *ptr = NULL, hints;
	SOCKET ConnectSocket;
	// For the future. So instead of printing the WSAError/whatever I 
	// can just return it and check the status (0/1) and the error returned
	struct ReturnStatus { char* ErrMsg; int status; };

public:
	tcpsocket();

	tcpsocket::ReturnStatus pconnect(char* IPAddress, char* Port);
	tcpsocket::ReturnStatus psend(char *);
	void pclose();
	char* precv(int bytes);
	


};

