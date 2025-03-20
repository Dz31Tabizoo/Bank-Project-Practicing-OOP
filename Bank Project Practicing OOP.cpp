
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
    cout << "\n\n Enter client Account Number: ";
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
        cout << "\n No Account Added ^_^\n";
        break;
    case clsBankClient::svSucceeded:
        cout << "\n Account Added Successfully ^_^\n";
        break;
    default:
        break;
    }
}

void DeleteClient()
{
    string AccountNumber = "";
    cout << "Enter a Account number To Delete\n";
    AccountNumber = clsInputValidation::ReadString();

    while (!clsBankClient::IsClientExiste(AccountNumber))
    {
        cout << "\nAcount Not founded,try again\n";
        AccountNumber = clsInputValidation::ReadString();
    }
    clsBankClient ClientToDelete = clsBankClient::Find(AccountNumber);
    ClientToDelete.Print();
    char answer = 'y';

    cout << "\nAre You sure you wanna delete this Client ? Press [Y] for yes / [N] for No\n";
    cin >> answer;

    if (tolower(answer)=='y')
    {
        if (ClientToDelete.Delete())
        {
            cout << "\n Client Deleted Successfully ^_^\n";
            ClientToDelete.Print();  // print an empty Object or Client
        }
        else
        {
            cout << "\nError Client Was Not Deleted\n";
        }
    }




}

int main()
{

    //Find whith Acc Number
 //   clsBankClient Client1 = clsBankClient::Find("A101");
  //  Client1.Print();
   // cout << "\n" << Client1.IsClientExiste("A101");
    //Find With Accnumber+Pincode
   // clsBankClient Client2 = clsBankClient::Find("A102", "4321");
    //Client2.Print();
    // udating
    //UpdateClient(Client2);
    //Add new
   // AddNewClient();
    DeleteClient();
    
    

    system("pause>0");
    return 0;
}

