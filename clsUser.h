#pragma once

#include "clsPerson.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Strings.h"
#include <string>
#include "clsDate.h"

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
	struct stLoginRegisterRecords; // public mumber
	
	static stLoginRegisterRecords _ConvertLoginRecordsLineTostRecords(string line)
	{
		stLoginRegisterRecords stRecord;
		vector <string> LoginRegDataLine = clsStrings::Split(line, "#//#");
		stRecord.Time = LoginRegDataLine[0];
		stRecord.UserName = LoginRegDataLine[1];
		stRecord.Password = LoginRegDataLine[2];
		stRecord.Permission = stoi( LoginRegDataLine[3]);

		return stRecord;
	}

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

	 string _PrepareLogIn(string Separator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSysetmDateTimeString() + Separator;
		LoginRecord += USERNAME + Separator;
		LoginRecord += PASSWORD + Separator;
		LoginRecord += to_string(PERMISSIONS);

		return LoginRecord;
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
		MyFile.open("Users.txt", ios::out); // delete all and wrie again Or create New and write if dosn't existe.

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
		Myfile.open("Users.txt", ios::out | ios::app);

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
		_vUsers = _LoadDataUsersFromFiles("Users.txt");

		for (auto& U : _vUsers)
		{
			if (U.USERNAME == this-> USERNAME)
			{
				U.Firstname = this->Firstname;
				U.Lastname = this->Lastname;
				U.Email = this->Email;
				U.Phone = this->Email;
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
	enum enPermissions { eAll = -1, pListClient = 1, pAddNewClient = 2, pDeleteClient = 4, pUdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLogInRegister = 128 };

	struct stLoginRegisterRecords
	{
		string Time;
		string UserName;
		string Password;
		int Permission;
	};

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
			return _GetEmptyUserObject();
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
			return _GetEmptyUserObject();
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

	bool CheckAccessPermission(enPermissions Perms)
	{
		return (this->PERMISSIONS == enPermissions::eAll) ? true : (((Perms & this->PERMISSIONS) == Perms) ? false : true) ;
	}

	void RegisterLogIn()
	{
		string stDataLine = _PrepareLogIn();
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static vector <stLoginRegisterRecords> GetLoginRegisterLiset()
	{
		vector<stLoginRegisterRecords>vRecords;
		
		fstream Myfile;
		Myfile.open("LoginRegister.txt", ios::in);

		if (Myfile.is_open())
		{
			string Line;
			stLoginRegisterRecords structRecords;
			while (getline(Myfile,Line))
			{
				structRecords = _ConvertLoginRecordsLineTostRecords(Line);
				vRecords.push_back(structRecords);
			}
		}

		return vRecords;
	}

};