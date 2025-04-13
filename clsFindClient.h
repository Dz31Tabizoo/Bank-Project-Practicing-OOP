#pragma once
#include "clsScreen.h"
#include "BankClient.h"
#include "clsInputValidation.h"

using namespace std;


class clsFindClient :protected clsScreen
{
private:
	static void _printClientRecord(clsBankClient Client)
	{
		Client.Print();
	}

public:

	static void FindClient()
	{
		if (!CheckAccessRights(clsUser::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("Find Client", "\t  Screen");
		cout << "\nEnter the Account Number you want to search: ";
		string AccountNumber = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExiste(AccountNumber))
		{
			cout << "\nWrong Account Number, Try again: ";
			 AccountNumber = clsInputValidation::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		cout << "\n\a-----------------------------------------------";
		_printClientRecord(Client);
	}


};

