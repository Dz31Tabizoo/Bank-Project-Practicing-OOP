#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsFindUserScree.h"
#include "Global.h"
#include "clsMainScreen.h"


class clsLoginScreen : public clsScreen
{
private:


	static bool _Login()
	{
		bool LoginFailed = false;
		string Username, PassWord;
		short counter = 3;

		do
		{
			if (LoginFailed)
			{
				
				system("cls");
				_DrawScreenHeader("Learning OOP", "\tLogin Screen");
				cout << "\nInvalide User Name / PassWord! \n\n";
				
					counter--;
					
					if (counter==0)
					{
						cout << "\nYou Are Locked after 3 trails !!!";
						system("pause>0");
						
						
						return false;
					}
					cout << "\nYou Have " << counter << " Trials To Login.";
				
			}
			cout << "\nEnter Username ? ";
			cin >> Username;
			cout << "\nEnter PassWord ?";
			cin >> PassWord;

			CurrentUser = clsUser::Find(Username, PassWord);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();

		return true;
	}


public:

	static bool LogIn()
	{
		system("cls");
		_DrawScreenHeader("Learning OOP", "\tLogin Screen");
		return _Login();

	}

};

