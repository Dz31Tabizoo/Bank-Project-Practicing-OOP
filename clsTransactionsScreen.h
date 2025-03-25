#pragma once

#include "clsScreen.h"
#include <iomanip>
#include <iostream>
#include"clsInputValidation.h"
#include"clsDepositScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
	enum _enTransactions
	{
		enDeposit = 1, enWithdrow = 2, enTotalBalances = 3, enMainMenue = 4
	};
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

	static void _PerformTansactionsMenue(_enTransactions TransChoise)
	{
		switch (TransChoise)
		{
		case clsTransactionsScreen::enDeposit:

			_ShowDepositScreen();
			
			break;
		case clsTransactionsScreen::enWithdrow:

			break;
		case clsTransactionsScreen::enTotalBalances:

			break;
		case clsTransactionsScreen::enMainMenue:

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
		system("cls");
		_DrawScreenHeader("Transaction Screen");

		cout << setw(38) << left << "" << "==============================" << endl;
		cout << setw(38) << left << "" << "\t\tTransactions Menue\n";
		cout << setw(38) << left << "" << "==============================" << endl;
		cout << setw(38) << left << "" << "\t[1] Deposit.\n";
		cout << setw(38) << left << "" << "\t[2] Withdrow.\n";
		cout << setw(38) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(38) << left << "" << "\t[4] Transac Menue.\n";

		_PerformTansactionsMenue(_enTransactions(_ReadTansactionsMenueChoise()));
	}

};

