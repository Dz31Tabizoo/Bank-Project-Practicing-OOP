#pragma once
#include "clsScreen.h"
#include<iostream>
#include"BankClient.h"
#include <iomanip>

using namespace std;

class clsClientListScreen : clsScreen
{
private:
    // to print one client info
    static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PIN_CODE;
        cout << "| " << setw(12) << left << Client.Account_Balance;

    }

public:

	static void ShowClientsList()
	{
        if (!CheckAccessRights(clsUser::pListClient))
        {
            return; // out of the function
        }
        vector <clsBankClient> vClients = clsBankClient::GetClientsFromFile();
        string title = "Client List Screen";
        string Subttl = "\t (" + to_string(vClients.size()) + ") Client(s)\n";
        _DrawScreenHeader(title, Subttl);

        cout <<setw(8)<< left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<setw(8) << left <<"" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout <<setw(8) <<"" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
        {
            cout << "\nNumber of Client is 0 -_-" << endl;
        }
        else
        {
            for (clsBankClient& C : vClients)
            {
                PrintClientRecordLine(C);
                cout << endl;
            }
        }
    }
};

