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

	static bool _TraqnsOperation(clsBankClient& Client1,clsBankClient& client2, int AmountTrans)
	{
		if (Client1.Account_Balance >= AmountTrans)
		{
			cout << "\nAre You Sure You Want To Execute This Operation ?  [Y/N]";
			char answer = ' ';
			cin >> answer;
			
			if (answer == 'y' || answer == 'Y')
			{
				Client1.Account_Balance -= AmountTrans;
				client2.Account_Balance += AmountTrans;


				

				cout << "\n\t--Transfer Secceed--";
				_PrintClientBalance(Client1);
				_PrintClientBalance(client2);

				return true;
			}
		}
		else
		{
			cout << "\nAccount Balance is insufisant!";
			return false;
		}

	}

	/// Abu-Hadhoud Used Deposit & Withdrow Functions.


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

			int AmountTransf;
			cout << "\n\n Enter the Amount you want to transfer:";
			AmountTransf = clsInputValidation::ReadIntNumber();

			if (_TraqnsOperation(Sender,Reciver,AmountTransf))
			{
				Sender.Save();
				Reciver.Save();
			}
	}
};

