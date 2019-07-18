#ifndef PACKET_H
#define PACKET_H

//#include <string.h>
#include <Windows.h>
//#include <tchar.h>

class Packet
{
private:
	int		NumberOfBytes;
	TCHAR	Data[1024];

public:
	Packet(const TCHAR*);
	~Packet();
	int	getNumberOfBytes();
};

#endif
