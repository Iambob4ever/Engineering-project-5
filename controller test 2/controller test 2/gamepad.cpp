#include "gamepad.h"
using namespace std;

Gamepad controller()
{
	
	Gamepad gamepad;

	bool wasConnected = true;

	while (true)
	{
		Sleep(100);
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

			if (gamepad.IsPressed(XINPUT_GAMEPAD_A))
				cout << "(A) button pressed" << endl;
			if (gamepad.IsPressed(XINPUT_GAMEPAD_B))
				cout << "(B) button pressed" << endl;
			if (gamepad.IsPressed(XINPUT_GAMEPAD_X))
				cout << "(X) button pressed" << endl;
			if (gamepad.IsPressed(XINPUT_GAMEPAD_Y))
				cout << "(Y) button pressed" << endl;
			if (gamepad.IsPressed(XINPUT_GAMEPAD_Y))
				cout << "(Y) button pressed" << endl;
			if (gamepad.IsPressed(XINPUT_GAMEPAD_LEFT_SHOULDER))
				cout << "(Left Shoulder) button pressed" << endl;
			if (gamepad.IsPressed(XINPUT_GAMEPAD_RIGHT_SHOULDER))
				cout << "(Right Shoulder) button pressed" << endl;

				*/


			Sleep(500);
			system("cls");
		}
	}
}