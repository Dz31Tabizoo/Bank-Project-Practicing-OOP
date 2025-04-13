#pragma once
#include "clsScreen.h"
#include"BankClient.h"
#include"clsInputValidation.h"
#include<iostream>
#include <iomanip>

using namespace std;

class clsDeleteClientScreen: protected clsScreen
{
private:
	static void _PrintClientInfo(clsBankClient Client)
	{
		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PIN_CODE;
		cout << "| " << setw(12) << left << Client.Account_Balance;

	}
    

public:

	static void DeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("Delete Client", "Screen");

		cout << "\nEnter Account Number to Delete: ";
		string AccountNumb = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExiste(AccountNumb))
		{
			cout << "\nAccount Number Dosn't Existe, try Again: ";
			string AccountNumb = clsInputValidation::ReadString();
		}
		clsBankClient CltoDelete=clsBankClient::Find(AccountNumb);
		_PrintClientInfo(CltoDelete);
		char answer;
		cout << "\n confirmation [Y] or No [N]: ";
		cin >> answer;
		if (answer == 'y' || tolower(answer) == 'y')
		{
			cout << "\nClient Deleted Succusfuly.";
			CltoDelete.Delete();
			_PrintClientInfo(CltoDelete);
		}
		else
		{
			cout << "\nError, Client Not Dleted.";
		}
	}

};

