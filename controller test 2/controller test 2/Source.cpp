#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <thread>
#include "gamepad.h"
#include <Xinput.h>
#include <mutex>

using std::cout;
using std::endl;
using std::thread;
using std::mutex;
void controller();
Gamepad gamepad;

mutex P1;



int main()
{
	
	thread P1(controller);
	
	while (1) {
		
		
		if (gamepad.IsPressed(XINPUT_GAMEPAD_A))
			cout << "(A)";
		if (gamepad.IsPressed(XINPUT_GAMEPAD_B))
			cout << "(B)";
		if (gamepad.IsPressed(XINPUT_GAMEPAD_X))
			cout << "(X)";
		if (gamepad.IsPressed(XINPUT_GAMEPAD_Y))
			cout << "(Y)"; 
		if (gamepad.IsPressed(XINPUT_GAMEPAD_LEFT_SHOULDER))
			cout << "Turning stepper counter Counter-clockwise";
		else if (gamepad.IsPressed(XINPUT_GAMEPAD_RIGHT_SHOULDER))
			cout << "Turning stepper counter clockwise" << endl;
	
		system("cls");
	
	}
}

void controller()
{
	while (1)
	{
		P1.lock();

		bool wasConnected = true;

		//checks if it can refresh
		if (!gamepad.Refresh())
		{
			if (wasConnected)
			{
				wasConnected = false;

				cout << "Please connect an Xbox 360 controller." << endl;
			}
		}
		else
		{
			if (!wasConnected)
			{
				wasConnected = true;

				cout << "Controller connected on port " << gamepad.GetPort() << endl;
			}
			/*
			cout << "Left thumb stick: (" << gamepad.leftStickX << ", " << gamepad.leftStickY << ")   Right thumb stick : (" << gamepad.rightStickX << ", " << gamepad.rightStickY << ")" << endl;

			cout << "Left analog trigger: " << gamepad.leftTrigger << "   Right analog trigger: " << gamepad.rightTrigger << endl;



			*/



			
		}
		P1.unlock();
	}
}

 