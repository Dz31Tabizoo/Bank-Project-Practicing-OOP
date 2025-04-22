#pragma once

#include"clsScreen.h"
#include<iostream>
#include<string>
#include<iomanip>
#include"clsInputValidation.h"
#include"clsClientListScreen.h"
#include"clsAddClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include "clsFindClient.h"
#include "clsTransactionsScreen.h"
#include "ManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterListScreen.h"
#include "clsCurrencyMainScreen.h"

using namespace std;


 class clsLoginScreen;

class clsMainScreen : protected clsScreen
{
private:

	enum enMainManueOptions {
		eListClient = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eMngUsers = 7, eFindClient = 5, eExit = 10, eTransaction = 6, eLoginRegister = 8, eCurrencyExchange =9
	};
	
	static void _ShowCurrencyMainScreen()
	{
		system("cls");
		clsCurrencyMainScreen::ShowCurrencyMainMenue();
		_GoBackToMainMenueScreen();

	}
	
	static void _ShowLoginRegisterList()
	{
		system("cls");
		clsLoginRegisterListScreen::LogInRegisterList();
		_GoBackToMainMenueScreen();
	}
	static void _GoBackToMainMenueScreen()
	{
		
		cout << "\n\tPress eny key to go back to main menue screen" << endl;
		system("pause>0");
		ShowMainMenue();
	}
	static void _ShowTransactionsMenue()
	{
		system("cls");
		clsTransactionsScreen::ShowTransactionsMenue();
		_GoBackToMainMenueScreen();
	}
	static void _ShowUpdateClientScreen()
	{
		system("cls");

		clsUpdateClientScreen::ShowUpdateClientScreen();

		_GoBackToMainMenueScreen();
	}
	static void _Logout()
	{
		
		CurrentUser = clsUser::Find(" ");

		if (CurrentUser.IsEmpty())
		{
			cout << "\a";
		}
		else
		{
			exit(1);
		}

	}
	static void _ShowAddNewClientsScreen()
	{
		system("cls");
		clsAddClientScreen::AddNewClientScreen();
		_GoBackToMainMenueScreen();
	}
	static void _ShowManageUsersScreen()
	{
		system("cls");
		ManageUsersScreen::ShowMageUSersMenue();
		_GoBackToMainMenueScreen();

	}
	static void _ShowAllClientsScreen()
	{
		system("cls");
		clsClientListScreen::ShowClientsList();
		_GoBackToMainMenueScreen();

	}
	static void _ShowFindClientScreen()
	{
		system("cls");
		clsFindClient::FindClient();
		
		_GoBackToMainMenueScreen();
	}
	static void _ShowDeletClientScreen()
	{
		system("cls");
		clsDeleteClientScreen::DeleteClientScreen();
		_GoBackToMainMenueScreen();
	}

	static void _PerformMainMenueOptions(enMainManueOptions Main_M_Option)
	{
		switch (Main_M_Option)
		{
		case clsMainScreen::eListClient:
			
			_ShowAllClientsScreen();
			
			
			break;
		case clsMainScreen::eAddNewClient:
			
			_ShowAddNewClientsScreen();

		case clsMainScreen::eDeleteClient:

			_ShowDeletClientScreen();
			
			break;
			
		case clsMainScreen::eUpdateClient:

			_ShowUpdateClientScreen();
			
			break;
		
		case clsMainScreen::eMngUsers:

			_ShowManageUsersScreen();
			
			break;
		case clsMainScreen::eFindClient:

			_ShowFindClientScreen();

			break;

		case clsMainScreen::eLoginRegister:
			_ShowLoginRegisterList();
			break;
		case clsMainScreen::eExit:
			
			_Logout();
			
			break;
		case eCurrencyExchange:
			_ShowCurrencyMainScreen();
			break;

			
		case clsMainScreen::eTransaction:
			
			_ShowTransactionsMenue();
			
			break;
		default:
			break;
		}
	}

	static short _ReadMainMenueOption()
	{
		cout << setw(38) << "" << "Choose What you want to do [1] to [9]:\n";
		short Choise = clsInputValidation::ReadshortBetween("\t\t\t\tWrong Choise, Please select your choise from 1 to 9:\n", 1, 9);
		return Choise;
	}



public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");

		cout << setw(38) << left << "" << "================================" << endl;
		cout << setw(38) << left << "" << "\t\tMain Menue\n";
		cout << setw(38) << left << "" << "================================" << endl;
		cout << setw(38) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(38) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(38) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(38) << left << "" << "\t[4] Update Client.\n";
		cout << setw(38) << left << "" << "\t[5] Find Client.\n";
		cout << setw(38) << left << "" << "\t[6] Transactions.\n";
		cout << setw(38) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(38) << left << "" << "\t[8] LogIn Register.\n";
		cout << setw(38) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(38) << left << "" << "\t10] Logout.\n";

		_PerformMainMenueOptions(enMainManueOptions(_ReadMainMenueOption()));
	}

};

