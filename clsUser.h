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

	static clsUser _ConvertLineToObj(string Line, string Separator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsStrings::Split(Line, Separator);

		return clsUser(enMode::UdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
	}

	static string _ConvertObjToLine(clsUser User, string Separator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += User.Firstname + Separator;
		stClientRecord += User.Lastname + Separator;
		stClientRecord += User.Email + Separator;
		stClientRecord += User.Phone + Separator;
		stClientRecord += User.USERNAME + Separator;
		stClientRecord += User.PASSWORD + Separator;
		stClientRecord += to_string(User.PERMISSIONS);

		return stClientRecord;

	}

	static vector <clsUser> _LoadDataUsersFromFiles(string FileName = "Users.txt")
	{
		vector <clsUser> vUSers;

		fstream Myfile;
		Myfile.open(FileName, ios::in);
		if (Myfile.is_open())
		{
			string Line;

			while (getline(Myfile, Line))
			{
				clsUser User = _ConvertLineToObj(Line);
				vUSers.push_back(User);
			}
			Myfile.close();
		}



		return vUSers;
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static void _SaveUSersDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("User.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (const auto& u : vUsers)  // const used to assure no modification /& avoid making copies
			{
				if (u._MarkForDelete == false)
				{

					MyFile << _ConvertObjToLine(u) << endl;
				}
			}
			MyFile.close();
		}
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream Myfile;
		Myfile.open("User.tst", ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << DataLine << endl;
			Myfile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertObjToLine(*this));
	}

	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadDataUsersFromFiles(_FileName);

		for (auto& U : _vUsers)
		{
			if (U.USERNAME == USERNAME)
			{
				U._Mode = this->_Mode;
				U._UserName = this->_UserName;
				U._PassWord = this->_PassWord;
				U._Permissions = this->_Permissions;
				U._MarkForDelete = this->_MarkForDelete;

				break;
			}
		}

		_SaveUSersDataToFile(_vUsers);
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
	void SetUserName(string usrnm)
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

	string GetFileName()
	{
		return _FileName;
	}

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
				else
				{
					return _GetEmptyUserObject();
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

	enSaveResults Save() // 
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

			_Update();

			break;
		case clsUser::AddNewMode:

			if (clsUser::IsUserExist(USERNAME))
			{
				return enSaveResults::svFaildUserExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UdateMode;
				return enSaveResults::svSucceeded;
			}


			break;
		}
	}

	static bool IsUserExist(string UserName)
	{

		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	bool Delete()
	{
		vector <clsUser> vUsers;
		vUsers = _LoadDataUsersFromFiles();

		for (auto& U : vUsers)
		{
			if (U.USERNAME == this->USERNAME)
			{
				U._MarkForDelete = true;

				break;
			}
		}

		_SaveUSersDataToFile(vUsers);

		this->_Mode = EmptyMode;
		this->Firstname = "";
		this->_UserName = "";
		this->_PassWord = "";
		this->_Permissions = 0;
		this->Lastname = "";
		this->Email = "";
		this->Phone = "";

		return true;

	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}
	
	static vector <clsUser> GetUsersList()
	{
		return _LoadDataUsersFromFiles();
	}

};