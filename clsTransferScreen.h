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

	static string _PrepareTransferRegister(clsBankClient Sender,clsBankClient Reciver,int TransAmount, string Separator = "#//#")
	{
		string Linerecord = "";
		Linerecord += clsDate::GetSysetmDateTimeString() + Separator;
		Linerecord += Sender.GetAccountNumber() + Separator;
		Linerecord += Reciver.GetAccountNumber() + Separator;
		Linerecord += to_string(TransAmount) + Separator;
		Linerecord += to_string (Sender.Account_Balance) + Separator;
		Linerecord += to_string(Reciver.Account_Balance) + Separator;
		Linerecord += CurrentUser.USERNAME;
		return Linerecord;
	}

	static void _PrintClientBalance(clsBankClient Client)
	{
		cout <<"\n" << Client.FullName() << "New Balance: " << Client.Account_Balance << endl;
	}

	static bool _TraqnsOperation(clsBankClient& Client1,clsBankClient& client2, int AmountTrans)
	{
		/// Abu-Hadhoud Used Deposit & Withdrow Functions.

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

	static void RegisterTransfersInFile(string DataLine)
	{
		fstream Myfile;
		Myfile.open("TransferLog.txt", ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << DataLine << endl;
			Myfile.close();
		}
	}


public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		string SenderAccNumb = _ReadAccountNumber("The Sender");
		clsBankClient Sender = clsBankClient::Find(SenderAccNumb);
		Sender.Print();
		cout << "\n----------------------";

		string ReciverAccNumb = _ReadAccountNumber("The Reciver");

			

			clsBankClient Reciver = clsBankClient::Find(ReciverAccNumb);
			Reciver.Print();

			while (!clsBankClient::IsClientExiste(SenderAccNumb)||!clsBankClient::IsClientExiste(ReciverAccNumb))
			{
				system("cls");
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
				RegisterTransfersInFile(_PrepareTransferRegister(Sender, Reciver, AmountTransf));

			}
	}
};

