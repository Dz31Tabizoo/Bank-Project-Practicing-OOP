#pragma once
#include "clsScreen.h"
#include "BankClient.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidation.h"
#include "clsWithdrowScreen.h"

using namespace std;
class clsDepositScreen:protected clsScreen
{
private:
	friend class clswithdrowScreen;

	static string _ReadAccountNumber()
	{
		cout << "\nEnter your Account Number: ";
		string AccountNumber = clsInputValidation::ReadString();
		return AccountNumber;
	}
	static void _PrintClient(clsBankClient client)
	{
		client.Print();
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");

		string AccountNumb = _ReadAccountNumber();
			

			while (!clsBankClient::IsClientExiste(AccountNumb))
			{
				cout << "\n" << AccountNumb << " Dosn't Existe, Try again.";
				string AccountNumber = clsInputValidation::ReadString();
			}

			clsBankClient Client = clsBankClient::Find(AccountNumb);
			_PrintClient(Client);
		
			double Depo = 0;
							
			cout << "\n Enter the Deposit Amount: ";
			Depo = clsInputValidation::ReadDoubleNumber();

			cout << "\nAre You Sure you Want to Perform this transaction? [Y],[N]";
			char answer;
			cin >> answer;

			if (answer == 'y' || tolower(answer) == 'y')
			{
				Client.Deposit(Depo);
				cout << "\nAmount Deposited Successfully.";
				cout << "\nNew Balance Is : " << Client.Account_Balance;
			}
			else
			{
				cout << "\nOperation was Canslled.\n";
			}
					
		
		
			
		
	}

};

