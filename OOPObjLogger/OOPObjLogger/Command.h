#ifndef COMMAND_H
#define COMMAND_H

class Command
{
private:
	const TCHAR* LOGGER_CMD_BREAK = L"break";
	const TCHAR* LOGGER_CMD_CONNECT = L"connect";
	const TCHAR* LOGGER_CMD_EXIT = L"exit";
	const TCHAR* LOGGER_CMD_START = L"start";
	const TCHAR* LOGGER_CMD_STOP = L"stop";
	TCHAR* EnteredCommand;	// holds the cmd entered by the user.


public:
	Command();	//Constructor
	~Command();	//Destructor

	void	Set(TCHAR*);	// set the value of the entered command
	TCHAR*	Get();			// Get the value/pointer of the entered command
	bool	IsBreak();		//checks what command
	bool	IsConnect();
	bool	IsExit();
	bool	IsStart();
	bool	IsStop();
	bool	IsValid();	// returns true if the entered command is valid
};

#endif
