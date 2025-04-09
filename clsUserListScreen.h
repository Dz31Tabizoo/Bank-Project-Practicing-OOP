#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "BankClient.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidation.h"
#include "clsWithdrowScreen.h"
#include <vector>


class clsUserListScreen : public clsScreen
{
private:

	static void _PrintUserLineRecord(clsUser user)
	{
        cout << setw(8) << left << "" << "| " << setw(12) << left << user.USERNAME;
        cout << "| " << setw(25) << left << user.FullName();
        cout << "| " << setw(12) << left << user.Phone;
        cout << "| " << setw(20) << left << user.Email;
        cout << "| " << setw(10) << left << user.PASSWORD;
        cout << "| " << setw(12) << left << user.PERMISSIONS;
	}

public:
    static void ShowUserList()
    {
        vector <clsUser> vUsers;
        vUsers = clsUser::GetUsersList();

        string title = "User List Screen";
        string Subttl = "\t (" + to_string(vUsers.size()) + ") Client(s)\n";

        _DrawScreenHeader(title, Subttl);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
        {
            cout << "\t\t\tNo Users Avalable In the System...";
        }
        else
        {
            for (const auto& USer : vUsers )
            {
                _PrintUserLineRecord(USer);
                cout << endl;
            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;
        }

    }







};

