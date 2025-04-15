#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "BankClient.h"


class clsTransferScreen :public clsScreen
{

	static string _ReadAccountNumber(string SenderOrReciver)
	{
		cout << "\nEnter " << SenderOrReciver <<" Account Number : ";
		string AccountNumber = clsInputValidation::ReadString();
		return AccountNumber;
	}

	static void _PrintClientBalance(clsBankClient Client)
	{
		cout <<"\n" << Client.FullName() << "New Balance: " << Client.Account_Balance << endl;
	}

	




public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		string SenderAccNumb = _ReadAccountNumber("The Sender");
		string ReciverAccNumb = _ReadAccountNumber("The Reciver");

			clsBankClient Sender = clsBankClient::Find(SenderAccNumb);

			clsBankClient Reciver = clsBankClient::Find(ReciverAccNumb);
		
			while (!clsBankClient::IsClientExiste(SenderAccNumb)||!clsBankClient::IsClientExiste(ReciverAccNumb))
			{
				cout << "Wrong Client Account Numbers";
				string SenderAccNumb = _ReadAccountNumber("The Sender");
				string ReciverAccNumb = _ReadAccountNumber("The Reciver");

			}







	}



};

