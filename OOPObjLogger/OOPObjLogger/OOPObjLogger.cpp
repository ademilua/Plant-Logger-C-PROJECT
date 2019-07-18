// OOPObjLogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include "Command.h"
#include "Client.h"
#include "Logger.h"
#include <thread>
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR *argv[])
{
	
	//checks that  file is included in argument, check project properties
	if (argc == 1)
	{
		_tcout << "Name of file missing." << endl
			<< "Usage: " << argv[0] << " [name-of-file.txt]\n" << endl;
		return 1;
	}

	fstream LoggerFile;		//create streamer
	LoggerFile.open(argv[1], fstream::in | fstream::out | fstream::app);
	if (!LoggerFile.good())
	{
		_tcout << "Could not create file." << strerror(errno) << "." << endl; //Check if streamer file is good
		return 1;
	}
	else
	{
		// Welcome message
		_tcout	<< "//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
				<< "//	Welcome to Object Oriented Programming Task 2" << endl
				<< "//	Object Oriented PlantLogger (C++)" << endl
				
				<< "//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
			<< endl << endl ;
		_tcout << "Type \"connect\" to begin: ";
	}

	//Create instances of Command, Client and Logger class
	Command Cmd;
	Client LoggerClient;
	Logger PlantLogger;

	//Create the thread for keyboard, Sending and Recieveing
	thread Keyboard(&Logger::Keyboard, ref(PlantLogger), &LoggerClient, &Cmd);
	thread Send(&Logger::Send, ref(PlantLogger), &LoggerClient, &Cmd);
	thread Recv(&Logger::Recv, ref(PlantLogger), &LoggerClient, &Cmd, &LoggerFile);

	//Helps thread to destroy safely
	Keyboard.join();
	Send.join();
	Recv.join();

	cout << "All thread terminated successfully";
	LoggerFile.close(); //saves log.

	//system("pause");
	return 0;
}


