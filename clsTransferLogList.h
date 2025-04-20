#pragma once
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "BankClient.h"

class clsTransferLogList : public clsScreen
{
private:
	static void _PrintTransferLineRecord(clsBankClient::stTransfLog TransLOG)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << TransLOG.Date;
		cout << "| " << setw(8) << left << TransLOG.ReciverACC;
		cout << "| " << setw(8) << left << TransLOG.SenderACC;
		cout << "| " << setw(8) << left << TransLOG.TransAmount;
		cout << "| " << setw(10) << left << TransLOG.ReciverNEwBalance;
		cout << "| " << setw(10) << left << TransLOG.SenderNewBalance;
		cout << "| " << setw(8) << left << TransLOG.CurrentUser;

	}


public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransfLog> TransRec;
		TransRec = clsBankClient::GetTransRecFromFile();

		string title = "Transfer Rec List";
		string SubTitle = to_string(TransRec.size()) + " Record(s)";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "\t| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (TransRec.size() == 0)
		{
			cout << "\t\t\t\tNo Transfers Available In the System!";
		}
		else
		{
			for (const auto& C : TransRec)
			{
				_PrintTransferLineRecord(C);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}



};

