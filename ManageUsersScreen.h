#pragma once

#include "clsScreen.h"
#include <iomanip>
#include <iostream>
#include "clsInputValidation.h"
#include "clsUserListScreen.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScrenn.h"
#include "clsUserUpdateScreen.h"

using namespace std;


class ManageUsersScreen : protected clsScreen
{
private :
	enum enUsers {
		enList = 1, enAddUSers = 2, enDeleteUSers = 3, enUpdateUSer = 4, enFindUser = 5, enMainMenueu = 6
	};

	static void _ShowUsersListScreen()
	{
		system("cls");
		clsUserListScreen::ShowUserList();
		_GobackToUserManageMenue();
	}

	static void _ShowUSerUpdateScrenn()
	{
		system("cls");
		clsUserUpdateScreen::ShowUSerUpdateScreen();
		_GobackToUserManageMenue();
	}

	static void _ShowAddNEwUserScreen()
	{
		system("cls");
		clsAddUserScreen::AddUserScreen();
		_GobackToUserManageMenue();
	}

	static void _ShowDeleteUSerScreen()
	{
		system("cls");
		clsDeleteUserScrenn::ShowDeleteUserScreen();
		_GobackToUserManageMenue();
	}

	static void _GobackToUserManageMenue()
	{
		cout << "\nPress any key to Go Back to User Manage Menue...";
		system("pause>0");
		ShowMageUSersMenue();
	}

	static short _ReadUsersMenueOption()
	{
		cout << setw(38) << "" << "Choose What you want to do [1] to [6]:\n";
		short Choise = clsInputValidation::ReadshortBetween("\t\t\t\tWrong Choise, Please select your choise from 1 to 4:\n", 1, 6);
		return Choise;
	}

	static void _performUserMenueChoises(enUsers Choise)
	{
		switch (Choise)
		{
		case ManageUsersScreen::enList:
			_ShowUsersListScreen();
			break;
		case ManageUsersScreen::enAddUSers:
			_ShowAddNEwUserScreen();
			break;
		case ManageUsersScreen::enDeleteUSers:
			_ShowDeleteUSerScreen();
			break;
		case ManageUsersScreen::enUpdateUSer:
			_ShowUSerUpdateScrenn();
			break;
		case ManageUsersScreen::enFindUser:
			break;
		case ManageUsersScreen::enMainMenueu:
			break;
		default:
			break;
		}

	}

public:

	static void ShowMageUSersMenue()
	{
		system("cls");
		_DrawScreenHeader("Users Managment","\t  Screen");

		cout << setw(38) << left << "" << "==============================" << endl;
		cout << setw(38) << left << "" << "\t\tManage Users Menue\n";
		cout << setw(38) << left << "" << "==============================" << endl;
		cout << setw(38) << left << "" << "\t[1] Users Liste.\n";
		cout << setw(38) << left << "" << "\t[2] Add Users \n";
		cout << setw(38) << left << "" << "\t[3] Delete USers.\n";
		cout << setw(38) << left << "" << "\t[4] Update Users.\n";
		cout << setw(38) << left << "" << "\t[5] Find Users.\n";
		cout << setw(38) << left << "" << "\t[6] Main Menue.\n";

		_performUserMenueChoises((enUsers)(_ReadUsersMenueOption()));
	}

};

