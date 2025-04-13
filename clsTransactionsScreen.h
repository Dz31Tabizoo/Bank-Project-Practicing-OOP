#pragma once

#include "clsScreen.h"
#include <iomanip>
#include <iostream>
#include"clsInputValidation.h"
#include"clsDepositScreen.h"
#include "clsTotalBalances.h"
#include "clsMainScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen 
{
private:

	enum _enTransactions
	{
		enDeposit = 1, enWithdrow = 2, enTotalBalances = 3, enMainMenue = 4
	};

	
	static void _ShowTotalbalancesScreen()
	{
		system("cls");

		clsTotalBalances::ShowTotalBalances();

		_GobackToTransactionMenue();
	}
	static void _GobackToTransactionMenue()
	{
		cout << "\nPress any key to Go Back to Transaction Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}
	
	static void _ShowDepositScreen() {
		system("cls");

		clsDepositScreen::ShowDepositScreen();

		_GobackToTransactionMenue();
	}

	static void _ShowWithdrowScreen()
	{
		system("cls");
		clsWithdrowScreen::ShowWithdrowScreen();
		_GobackToTransactionMenue;
	}

	static void _PerformTansactionsMenue(_enTransactions TransChoise)
	{
		switch (TransChoise)
		{
		case clsTransactionsScreen::enDeposit:

			_ShowDepositScreen();
			
			break;
		case clsTransactionsScreen::enWithdrow:
			
			_ShowWithdrowScreen();
			
			break;
		case clsTransactionsScreen::enTotalBalances:
			_ShowTotalbalancesScreen();

			break;
		case clsTransactionsScreen::enMainMenue:
          
			cout << "\n to be filled ^later^...";
			break;
		default:

			break;
		}
	}
	
	static short _ReadTansactionsMenueChoise()
	{
		cout << setw(38) << "" << "Choose What you want to do [1] to [4]:\n";
		short Choise = clsInputValidation::ReadshortBetween("\t\t\t\tWrong Choise, Please select your choise from 1 to 4:\n", 1, 4);
		return Choise;
	}

public:

	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::pTransactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("Transaction Screen");

		cout << setw(38) << left << "" << "==============================" << endl;
		cout << setw(38) << left << "" << "\t\tTransactions Menue\n";
		cout << setw(38) << left << "" << "==============================" << endl;
		cout << setw(38) << left << "" << "\t[1] Deposit.\n";
		cout << setw(38) << left << "" << "\t[2] Withdrow.\n";
		cout << setw(38) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(38) << left << "" << "\t[4] Main Menue.\n";

		_PerformTansactionsMenue(_enTransactions(_ReadTansactionsMenueChoise()));
	}

};

