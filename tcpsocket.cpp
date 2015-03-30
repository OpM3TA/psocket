#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "tcpsocket.h"




tcpsocket::tcpsocket()
{
	WSADATA wsaData;

	// Initialize Winsock
	pResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	// Setup the socket stuff
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

}



/// SOO tired!
// I hope I am not making too many mistakes
char * tcpsocket::precv(int buffer)
{
	int bytes_recv = 0;
	char *toRecv = new char[buffer+1]; // I hope this isn't unnecessary
	memset(toRecv, 0x0, buffer); // Bad junkie
	bytes_recv = recv(ConnectSocket, toRecv, buffer, 0);

	return toRecv;
}

void tcpsocket::pclose()
{
	closesocket(ConnectSocket);
	WSACleanup();
	printf("Closed Socket -> %u\n", ConnectSocket);
}

int tcpsocket::psend(char * sendbuf)
{
	pResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	return pResult;
}



int tcpsocket::pconnect(char* IPAddress, char * Port)
{

	pResult = getaddrinfo(IPAddress, Port, &hints, &result);
	if (pResult != 0) {
		WSACleanup();
		return WSAGetLastError();
	}

	ConnectSocket = INVALID_SOCKET;
	ptr = result;
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

	if (ConnectSocket == INVALID_SOCKET) {
		freeaddrinfo(result);
		WSACleanup();
		return WSAGetLastError();
	}

	pResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

	if (pResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		return WSAGetLastError();
	}
	
	return 0;
}
