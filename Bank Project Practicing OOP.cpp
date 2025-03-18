
#include <iostream>
#include "BankClient.h"
#include "clsPerson.h"
#include "clsInputValidation.h"

using namespace std;

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


}

int main()

{
    //Find whith Acc Number
    clsBankClient Client1 = clsBankClient::Find("A101");
    Client1.Print();
    cout << "\n" << Client1.IsClientExiste("A101");
    //Find With Accnumber+Pincode
    clsBankClient Client2 = clsBankClient::Find("A102", "1234");
    Client2.Print();



    system("pause>0");
    return 0;
}

