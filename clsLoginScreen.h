#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsFindUserScree.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : public clsScreen
{
private:
	static void _Login()
	{
		bool LoginFailed = false;
		string Username, PassWord;

		do
		{
			if (LoginFailed)
			{
				cout << "\nInvalide User Name / PassWord! \n\n";
			}
			cout << "Enter Username ? ";
			cin >> Username;
			cout << "\nEnter PassWord ?";
			cin >> PassWord;

			CurrentUser = clsUser::Find(Username, PassWord);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenue();

	}


public:
	static void LogIn()
	{
		system("cls");
		_DrawScreenHeader("Learning OOP", "Login Screen");
		_Login();

	}

};

