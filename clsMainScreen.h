#pragma once

#include"clsScreen.h"
#include<iostream>
#include<string>
#include<iomanip>
#include"clsInputValidation.h"

using namespace std;



class clsMainScreen : protected clsScreen
{
private:

	enum enMainManueOptions {
		eListClient = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eMngUsers = 7, eFindClient = 5, eLogout = 8, eTransaction = 6
	};
	enum enTransactions
	{
		enDeposit = 1, enWithdrow = 2, enTotalBalances = 3, enMainMenue = 4
	};

	enum enUsers {
		enList = 1, enAddUSers = 2, enDeleteUSers = 3, enUpdateUSer = 4, enFindUser = 5, enMainMenueu = 6
	};

	static void _GoBackToMainMenueScreen()
	{
		system("cls");
		cout << "Press eny key to go back to main menue screen" << endl;
		system("pause>0");
		ShowMainMenue();
	}

	static void _PerformMainMenueOptions(enMainManueOptions Main_M_Option)
	{
		switch (Main_M_Option)
		{
		case clsMainScreen::eListClient:
			system("cls");
			_GoBackToMainMenueScreen();
			break;
		case clsMainScreen::eAddNewClient:
			system("cls");
			_GoBackToMainMenueScreen();
			break;
		case clsMainScreen::eDeleteClient:
			system("cls");
			_GoBackToMainMenueScreen();
			break;
		case clsMainScreen::eUpdateClient:
			system("cls");
			_GoBackToMainMenueScreen();
			break;
		case clsMainScreen::eMngUsers:
			system("cls");
			_GoBackToMainMenueScreen();
			break;
		case clsMainScreen::eFindClient:
			system("cls");
			_GoBackToMainMenueScreen();
			break;
		case clsMainScreen::eLogout:
			system("cls");
			_GoBackToMainMenueScreen();
			break;
		case clsMainScreen::eTransaction:
			system("cls");
			//go back to transactions screen
			break;
		default:
			break;
		}
	}

	static short _ReadMainMenueOption()
	{
		cout << setw(38) << "" << "Choose What you want to do [1] to [8]:\n";
		short Choise = clsInputValidation::ReadshortBetween("\t\t\t\tWrong Choise, Please select your choise from 1 to 8:\n", 1, 8);
		return Choise;
	}



public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");

		cout << setw(38) << left << "" << "==============================" << endl;
		cout << setw(38) << left << "" << "\t\tMain Menue\n";
		cout << setw(38) << left << "" << "==============================" << endl;
		cout << setw(38) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(38) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(38) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(38) << left << "" << "\t[4] Update Client.\n";
		cout << setw(38) << left << "" << "\t[5] Find Client.\n";
		cout << setw(38) << left << "" << "\t[6] Transactions.\n";
		cout << setw(38) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(38) << left << "" << "\t[8] Logout.\n";
		_PerformMainMenueOptions(enMainManueOptions(_ReadMainMenueOption()));
	}

};

