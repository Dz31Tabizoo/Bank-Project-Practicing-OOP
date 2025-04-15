#pragma once

#include "clsScreen.h"
#include "clsUser.h"
#include <iostream>
#include <iomanip>
#include "clsInputValidation.h"

using namespace std;

class clsAddUserScreen : public clsScreen
{
private:
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

	static void PrintUSerRecordLine(clsUser User)
	{

		cout << "| " << setw(15) << left << User.USERNAME;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.PASSWORD;
		cout << "| " << setw(10) << left << User.PERMISSIONS;

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

		cout << "\nLogIn Register List ? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Perm += clsUser::enPermissions::pLogInRegister;
		}

	}

	

public:

	static void AddUserScreen()
	{
		_DrawScreenHeader("Add User Screen");
		string UserName = "";
		printf("\nEnter a UserName :");
		UserName = clsInputValidation::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			printf("\nUser Name Already existe Enter another UserName :");
			UserName = clsInputValidation::ReadString();

		}
		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		
		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SVResult;

		SVResult = NewUser.Save();

		switch (SVResult)
		{
		case clsUser::svFildEmptyObject:
			cout << "\nAdding New User Field -_- Empty User";
			break;
		case clsUser::svSucceeded:
			cout << "\n Account Added Successfully ^_^\n";
			PrintUSerRecordLine(NewUser);
			break;
		case clsUser::svFaildUserExist:
			cout << "\n Account already Existe !\n";
			break;
		default:
			break;
		}

	}






};

