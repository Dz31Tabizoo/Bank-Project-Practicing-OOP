#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidation.h"

class clsDeleteUserScrenn : public clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.Firstname;
		cout << "\nLastName    : " << User.Lastname;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.USERNAME;
		cout << "\nPassword    : " << User.PASSWORD;
		cout << "\nPermissions : " << User.PERMISSIONS;
		cout << "\n___________________\n";

	}







public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");
		string UserNameToDelete = "";
		cout << "\nEnter a User Name To Delete:";
		UserNameToDelete = clsInputValidation::ReadString();

		while (!clsUser::IsUserExist(UserNameToDelete))
		{
			cout << "\nUser Name dosn't existe try again :";
			UserNameToDelete = clsInputValidation::ReadString();
		}

		clsUser User_toDel = clsUser::Find(UserNameToDelete);
		_PrintUser(User_toDel);

		char answer = ' ';
		cout << "\nAre You Sure You Want To Delete This User " << UserNameToDelete << " ? Y/N";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (User_toDel.Delete())
			{
				cout << "\nUser Deleted Succsessfully.";
				_PrintUser(User_toDel);
			}
			else
			{
				cout << "\nError User Was Nnot Deleted";
			}
		}


	}


};

