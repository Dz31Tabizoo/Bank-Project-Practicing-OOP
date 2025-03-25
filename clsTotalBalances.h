#pragma once
#include "clsScreen.h"
#include "BankClient.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidation.h"
#include "clsDepositScreen.h"


class clsTotalBalances : protected clsScreen
{
    static void _PrintClientRecordLineBalances(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Account_Balance;

    }


public:
    static void ShowTotalBalances()
    {
        _DrawScreenHeader("Total Balances");
        vector <clsBankClient> vClients = clsBankClient::GetClientsFromFile();
        double Total = 0;
        cout << "\n\t\t\t\t\t\t (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
        {
            cout << "\nTotal balances = 0, there is no Client in Liste\n";
        }
        else
        {
            for (clsBankClient& C : vClients)
            {
                _PrintClientRecordLineBalances(C);
                Total += C.Account_Balance;
                cout << endl;
            }
        }

        cout << "\n\t\t\tTotal Balances = " << Total << "DZA.";
        cout << "\n_______________________________________________________";

    }
};

