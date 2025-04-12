#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsUser.h"

class clsFindUserScree : public clsScreen
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
	static void FindUserScreen()
	{
		clsScreen::_DrawScreenHeader("Find User Screen");

		string Username = "";
		cout << "\nEnter a USer Name To Find :";
		cin >> Username;

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUser dosn't Existe! Enter a Different USer Name:";
			cin >> Username;
		}
		clsUser UserToFind = clsUser::Find(Username);
		_PrintUser(UserToFind);

	}


};

