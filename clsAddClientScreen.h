#pragma once

#include "clsScreen.h"
#include "BankClient.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsAddClientScreen : protected clsScreen
{
private:

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

   static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PIN_CODE;
        cout << "| " << setw(12) << left << Client.Account_Balance;

    }

public:

	static void AddNewClientScreen()
	{
        if (!CheckAccessRights(clsUser::pAddNewClient))
        {
            return;
        }
        _DrawScreenHeader("Add New Clien Screen");

        string AccountNumb = "";
        cout << "\nEnter Account Number: ";
        AccountNumb = clsInputValidation::ReadString();

        while (clsBankClient::IsClientExiste(AccountNumb))
        {
            cout << "\n Account Number already existe Please try another one.";
            AccountNumb = clsInputValidation::ReadString();
        }
        clsBankClient NewClient = clsBankClient::_GetAddNewClientObject(AccountNumb);

        _ReadClientInfo(NewClient);
        
        clsBankClient::enSaveResult SaveRes;
        
        SaveRes = NewClient.Save();

        switch (SaveRes)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "\n No Account Added ^_^\n";
            break;
        case clsBankClient::svSucceeded:
                     
            cout << "\n Account Added Successfully ^_^\n";
            PrintClientRecordLine(NewClient);
            break;
        default:
            break;
        }
	}




};

