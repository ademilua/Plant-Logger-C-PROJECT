#include "pch.h"
#include "Packet.h"


Packet::Packet(const TCHAR* pString)
{
	int pStringLength = _tcslen(pString) + 1; // include terminating null _tcsclen 
	int stringByteLength = pStringLength * sizeof(TCHAR);

	this->NumberOfBytes = 4 + stringByteLength;
	wcscpy_s(this->Data, pString);
}


Packet::~Packet() //ones complement operator/destructor
{
}


int Packet::getNumberOfBytes()
{
	return this->NumberOfBytes;
}
