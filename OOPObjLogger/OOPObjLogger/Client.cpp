#include "pch.h"
#include "Client.h"

using namespace std; 

Client::Client()
{
	//_tcout << "Client Class Initialized" << endl;
	WSADATA	WsaData;
	int Error = WSAStartup(MAKEWORD(2, 2), &WsaData); //for error and start up of Winsock word and Address

	if (Error)
	{
		_tcout << "Unable to load Winsock: " << Error << endl;
		exit(0);
	}

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	addr.sin_port = htons(SERVER_PORT);
}


Client::~Client()
{
}


SOCKET	Client::GetSocket()
{
	return this->ConnectSocket;
}

//checks if clients Socket is valid
bool Client::Valid()
{
	SOCKET& Conn = this->ConnectSocket;
	if (Conn == INVALID_SOCKET)
		return FALSE;
	return true;
}


bool Client::Connect()
{
	// create a shorter alias for class ConnectSocket bcos I can!
	SOCKET& Conn = this->ConnectSocket;

	// initiate connection
	Conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (Conn == INVALID_SOCKET)
		return FALSE;

	if (connect(Conn, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR)
		return FALSE;

	char RecvBuf[128] = { 0 };
	if (recv(Conn, RecvBuf, MAX_BYTE, 0) <= 0) // check server response
		return FALSE;

	// send password
	if (this->Send(PASSWORD))
	{
		if (recv(Conn, RecvBuf, MAX_BYTE, 0) <= 0) // check server response
			return FALSE;
	}
	return TRUE;
}


void Client::Disconnect()
{
	// create a shorter alias for class ConnectSocket bcos I can!
	SOCKET& Conn = this->ConnectSocket;
	// clear sockets
	if (Conn != INVALID_SOCKET)
	{
		closesocket(Conn);
		//WSACleanup();
	}
	//this->Connected = false;
}


int Client::_Send(const TCHAR* data)
{
	SOCKET& Conn = this->ConnectSocket;

	Packet Packet(data);
	int SentBytes = 0;

	while (SentBytes < Packet.getNumberOfBytes())
	{
		int res = send(Conn, (char*)&Packet + SentBytes, 
						Packet.getNumberOfBytes() - SentBytes, 0);
		if (res == SOCKET_ERROR)
		{
			throw exception();
			//_tcout << L"WSASendxx failed with error: " << WSAGetLastError() << endl;
			break;
		}
		SentBytes += res; 
	}

	return SentBytes;
}

int Client::Send(const TCHAR* data)
{
	try {
		return this->_Send(data);
	}
	catch (exception e)
	{
		_tcout << "Sending failed." << endl;
	}
	return 0;
}
