#pragma once

#include "clsPerson.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Strings.h"
#include <string>

using namespace std;

class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _PassWord;
	int _Permissions;

	bool _MarkForDelete = false;
	const string _FileName = "User.txt";

	static clsUser _ConvertLineToObj(string Line,string Separator = "#[]#")
	{
		vector<string> vUserData;
		vUserData = clsStrings::Split(Line, Separator);

		return clsUser(enMode::UdateMode, vUserData[0], vUserData[1], vUserData[2],vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
	}


public:
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string PassWord, int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_PassWord = PassWord;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}
		
	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string usrnm )
	{
		_UserName = usrnm;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string USERNAME;

	string GetPassWord()
	{
		return _PassWord;
	}
	void SetPAssWord(string PassW)
	{
		_PassWord = PassW;
	}
	__declspec(property(get = GetPassWord, put = SetPassWord)) string PASSWORD;

	int GetPErmissions()
	{
		return _Permissions;
	}
	void SetPErmissions(int Perms)
	{
		_Permissions = Perms;
	}
	__declspec(property(get = GetPErmissions, put = SetPErmissions))int PERMISSIONS;

	static clsUser Find(string UserName)
	{
		fstream Myfile;
		Myfile.open("Users.txt", ios::in); // To Read
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsUser User = _ConvertLineToObj(Line);
				if (User.USERNAME == UserName)
				{
					Myfile.close();
					return User;
				}
			}
		}
		Myfile.close();

	}

	static clsUser Find(string UserName, string Password)
	{
		fstream Myfile;
		Myfile.open("Users.txt", ios::in); // To Read
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsUser User = _ConvertLineToObj(Line);
				if (User.USERNAME == UserName && User.PASSWORD == Password)
				{
					Myfile.close();
					return User;
				}
			}
		}
		Myfile.close();
	}

	enum enSaveResults { svFildEmptyObject = 0, svSucceeded = 1, svFaildUserExist = 2 };

	enSaveResults Save() // to be contuned:=-=-=-=-===-
	{
		switch (_Mode)
		{
		case clsUser::EmptyMode:
			if (IsEmpty())
			{
				return enSaveResults::svFildEmptyObject;
			}
			break;
		case clsUser::UdateMode:
			//_Update();
			break;
		case clsUser::AddNewMode:
			
			return 
			break;
		default:
			break;
		}
	}

};

