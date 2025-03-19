
#include <iostream>
#include "BankClient.h"
#include "clsPerson.h"
#include "clsInputValidation.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
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

void UpdateClient(clsBankClient& Client)
{
    string AccountNumber = "";

    cout << "\nenter client Account Number: ";
    AccountNumber = clsInputValidation::ReadString();

    while (!clsBankClient::IsClientExiste(AccountNumber))
    {
        cout << "\nAccount Number Not found, Enter another One";
        AccountNumber = clsInputValidation::ReadString();

    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\n   Updating Client Info     ";
    cout << "\n-------------------------------\n";

    ReadClientInfo(Client1);
    clsBankClient::enSaveResult SaveResult;
    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case clsBankClient::svFaildEmptyObject:
        cout << "\nError, account was not saved because it's emty\n";
        break;
    case clsBankClient::svSucceeded:
        cout << "\n Account Updated Successfully ^_^\n";
        Client1.Print();
        break;
    default:
        break;
    }
}

void AddNewClient()
{
    string AccountNumber = "";
    cout << "\nEnter client Account Number: ";
    AccountNumber = clsInputValidation::ReadString();

    while (clsBankClient::IsClientExiste(AccountNumber))
    {
        cout << "\nAccount Number already existe, Enter another One";
        AccountNumber = clsInputValidation::ReadString();

    }
    clsBankClient NewClient = clsBankClient::_GetAddNewClientObject(AccountNumber);
    ReadClientInfo(NewClient);

    clsBankClient::enSaveResult SaveResult;
    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::svFaildEmptyObject:
        break;
    case clsBankClient::svSucceeded:
        break;
    default:
        break;
    }
}

int main()
{
    //Find whith Acc Number
    clsBankClient Client1 = clsBankClient::Find("A101");
    Client1.Print();
    cout << "\n" << Client1.IsClientExiste("A101");
    //Find With Accnumber+Pincode
    clsBankClient Client2 = clsBankClient::Find("A102", "4321");
    Client2.Print();



    
    

    system("pause>0");
    return 0;
}

