#pragma once
#include "clsScreen.h"
#include"BankClient.h"
#include"clsInputValidation.h"
#include<iostream>
#include <iomanip>

using namespace std;
class clsUpdateClientScreen : protected clsScreen
{
private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PIN_CODE;
        cout << "| " << setw(12) << left << Client.Account_Balance;

    }

	static void _ReadClientInfo(clsBankClient& Client)
	{
        cout << "\nEnter FirstName: ";

        Client.Firstname = clsInputValidation::ReadString();

        cout << "\nEnter LastName: ";
        Client.Lastname = clsInputValidation::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidation::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidation::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PIN_CODE = clsInputValidation::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.Account_Balance = clsInputValidation::ReadDoubleNumber();
	}

public:
	static void ShowUpdateClientScreen()
	{
        if (!CheckAccessRights(clsUser::pUdateClient))
        {
            return;
        }
        _DrawScreenHeader("Update Clients", "\t    Screen");
        cout << "\nEnter a Account Number to Update: ";
        string AccountNumber ;
        AccountNumber = clsInputValidation::ReadString();

        while (!clsBankClient::IsClientExiste(AccountNumber))
        {
            cout << "\nWrong Account Number, try again: ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Client.Print();
        cout << "\a\n \t\t Updating::";

        _ReadClientInfo(Client);

        clsBankClient::enSaveResult SaveRES;

        SaveRES = Client.Save();

        switch (SaveRES)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "\nOops Some think is wrong";
            break;
        case clsBankClient::svSucceeded:
            cout << "\n \aSaved Succeeded";
                break;
        case clsBankClient::FailedAccountNumberEsiste:
            break;
        default:
            break;
        }


	}
};

