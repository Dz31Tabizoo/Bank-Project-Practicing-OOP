#pragma once
#include "clsScreen.h"
#include "BankClient.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidation.h"
#include "clsDepositScreen.h"

class clsWithdrowScreen: protected clsScreen 
{
private:
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
	static void ShowWithdrowScreen()
	{
		_DrawScreenHeader("Withdrow Screen");
		
		string AccountNumb = _ReadAccountNumber();


		while (!clsBankClient::IsClientExiste(AccountNumb))
		{
			cout << "\n" << AccountNumb << " Dosn't Existe, Try again.";
			string AccountNumber = clsInputValidation::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumb);
		_PrintClient(Client);

		double withdr = 0;

		cout << "\n Enter the Withdrow Amount: ";
		withdr = clsInputValidation::ReadDoubleNumber();

		cout << "\nAre You Sure you Want to Perform this transaction? [Y],[N]";
		char answer;
		cin >> answer;

		if (answer == 'y' || tolower(answer) == 'y')
		{
			Client.Withdrow(withdr);
			cout << "\nAmount Withdrod Successfully.";
			cout << "\nNew Balance Is : " << Client.Account_Balance;
		}
		else
		{
			cout << "\nOperation was Canslled.\n";
		}

	}




};

