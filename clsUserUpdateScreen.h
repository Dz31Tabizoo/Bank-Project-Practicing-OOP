#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidation.h"
using namespace std;


class clsUserUpdateScreen : public clsScreen
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

	static void _ReadUserInfo(clsUser& User)
	{
		printf("\nEnter First Name :");
		User.Firstname = clsInputValidation::ReadString();
		printf("\nEnter Last Name :");
		User.Lastname = clsInputValidation::ReadString();
		printf("\nEnter User Email :");
		User.Email = clsInputValidation::ReadString();
		printf("\nEnter User N.Phone :");
		User.Phone = clsInputValidation::ReadString();
		printf("\nEnterUser PassWord :");
		User.SetPAssWord(clsInputValidation::ReadString());
		printf("\nPermissions :");
		User.PERMISSIONS = _ReadPermissions();
	}

	static int _ReadPermissions()
	{
		int Perm = 0;
		char answer = 'n';

		cout << "\nGive Full Access ? Y / N";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			return -1;
		}
		cout << "Do You Want To Give Access to: \n";

		cout << "\nShow Client List? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Perm += clsUser::enPermissions::pListClient;

		}

		cout << "\nAdd New Client? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Perm += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Perm += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Perm += clsUser::enPermissions::pUdateClient;
		}

		cout << "\nFind Client? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Perm += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Perm += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Perm += clsUser::enPermissions::pManageUsers;
		}

	}

public:
	static void ShowUSerUpdateScreen()
	{
		_DrawScreenHeader("User Update Screen");
		string UserName_toUpdt;

		cout << "\nEnter a User Name to Update : ";
		UserName_toUpdt = clsInputValidation::ReadString();

		while (!clsUser::IsUserExist(UserName_toUpdt))
		{
			cout << "User Name is not found, Try Again:";
			UserName_toUpdt = clsInputValidation::ReadString();
		}

		clsUser UserUp = clsUser::Find(UserName_toUpdt);

		_PrintUser(UserUp);
		
		cout << "\nAre you sure you want to update this User y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			_ReadUserInfo(UserUp);
			
			clsUser::enSaveResults SaveUpd;
			SaveUpd = UserUp.Save();

			switch (SaveUpd)
			{
			case clsUser::svFildEmptyObject:
				cout << "\nError User was not saved because it's Empty";
				break;
			case clsUser::svSucceeded:
				cout << "\nUser Updated Successfully :-)\n";

				_PrintUser(UserUp);
				break;
			
			default:
				break;
			}

		}


	}




};

