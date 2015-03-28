#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "tcpsocket.h"




tcpsocket::tcpsocket()
{
	WSADATA wsaData;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

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

	// Receive some data
	bytes_recv = recv(ConnectSocket, toRecv, buffer, 0);

	return toRecv;
}

void tcpsocket::pclose()
{
	closesocket(ConnectSocket);
	WSACleanup();
	printf("Closed Socket -> %u\n", ConnectSocket);
}

tcpsocket::ReturnStatus tcpsocket::psend(char * sendbuf)
{
	ReturnStatus psendStatus;
	psendStatus.status = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	return psendStatus;
}
tcpsocket::ReturnStatus tcpsocket::pconnect(char* IPAddress, char * Port)
{
	ReturnStatus pconnectStatus;
	pconnectStatus.status = 0;
	pconnectStatus.ErrMsg = "OK";
	iResult = getaddrinfo(IPAddress, Port, &hints, &result);
	if (iResult != 0) {
		pconnectStatus.ErrMsg, "getaddrinfo failed";
		pconnectStatus.status = 1;
		WSACleanup();
		return pconnectStatus;
	}

	ConnectSocket = INVALID_SOCKET;
	ptr = result;
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

	if (ConnectSocket == INVALID_SOCKET) {
		pconnectStatus.ErrMsg = "Error on socket()";
		freeaddrinfo(result);
		WSACleanup();
		pconnectStatus.status = 1;
		return pconnectStatus;
	}

	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

	if (iResult == SOCKET_ERROR) {
		pconnectStatus.ErrMsg = "Error on connect()";
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		pconnectStatus.status = 1;
		
		return pconnectStatus;
	}
	
	return pconnectStatus;
}
