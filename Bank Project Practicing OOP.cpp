
#include <iostream>
#include "BankClient.h"
#include "clsPerson.h"
using namespace std;

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

