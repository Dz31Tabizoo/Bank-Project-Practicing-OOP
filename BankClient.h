#pragma once
#include "clsPerson.h"
#include "Strings.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UdpateMode = 1, AddNewMode = 2 };
	enMode _mode;
	string _accountnumber;
	string _pincode;
	float _accountbalance;
	bool _MarkforDelete = 0;

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.Firstname + Seperator;
		stClientRecord += Client.Lastname + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.PIN_CODE + Seperator;
		stClientRecord += to_string(Client.Account_Balance);

		return stClientRecord;
	}
	static clsBankClient _ConvertLinetoClientObject(string Line, string Separator = "#//#")
	{
		vector<string>vClient;
		vClient = clsStrings::Split(Line, Separator);

		return clsBankClient(enMode::UdpateMode, vClient[4], vClient[5], vClient[0], vClient[1], vClient[2], vClient[3], stod(vClient[6]));
	}
	
	void _AddDataLineToFile(string Dataline)
	{
		fstream Myfile;
		Myfile.open("Clients.txt",ios::out | ios::app);
		if (Myfile.is_open())
		{
			Myfile << Dataline << endl;
			Myfile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	
	static vector <clsBankClient> _LoadClientDataFromFile()
	{
		vector<clsBankClient> vClient;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClient.push_back(Client);
			}
			MyFile.close();
		}

		return vClient;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient c : vClients)
			{
				if (c.MarkeForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(c);
					MyFile << DataLine << endl;
				}
				
			}
			
		}
		MyFile.close();
	}
	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();
		
		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}
		}		
		_SaveClientsDataToFile(_vClients);
	}
	
public:
	// CONSTRUCTOR
	clsBankClient(enMode mode, string accountnub, string pin, string firstname, string lastname, string email, string phone, float accountbalance) :clsPerson(firstname, lastname, email, phone)
	{
		_mode = mode;
		_accountnumber = accountnub;
		_pincode = pin;
		_accountbalance = accountbalance;
	}

	//properties
	void SetMarkforDelete(bool X)
	{
		_MarkforDelete = X;
	}
	bool GetMarkforDelete()
	{
		return _MarkforDelete;
	}
	__declspec(property(get = GetMarkforDelete, put = SetMarkforDelete)) bool MarkeForDelete;

	bool IsEmpty()
	{
		return (_mode == enMode::EmptyMode);
	}

	string GetAccountNumber()
	{
		return this->_accountnumber;
	}

	void SetAccountbalance(float newbalance)
	{
		_accountbalance = newbalance;
	}
	float GetAccountBalance()
	{
		return _accountbalance;
	}
	_declspec(property(get = GetAccountBalance, put = SetAccountbalance)) float Account_Balance;

	void SetPincode(string pin)
	{
		_pincode = pin;
	}
	string GetPinCode() {
		return this->_pincode;
	}
	__declspec(property(get = GetPinCode, put = SetPincode)) string PIN_CODE;

	void Print()
	{
		cout << "\nClient Card: ";
		cout << "\n---------------------";
		cout << "\nFirst Name   : " << Firstname;
		cout << "\nLast Name    : " << Lastname;
		cout << "\nFull Name    : " << FullName();
		cout << "\nEmail        : " << Email;
		cout << "\nPhone        : " << GetPhone();
		cout << "\nAcc~Number   : " << _accountnumber;
		cout << "\nPassWord     : " << PIN_CODE;
		cout << "\nBALANCE      : " << Account_Balance;
		cout << "\n---------------------";
	}

	static clsBankClient _GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, AccountNumber, "", "", "", "", "", 0);
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient Find(string Account_Number)
	{
		vector <clsBankClient> vClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);

				if (Client.GetAccountNumber() == Account_Number)
				{
					MyFile.close();
					return Client;
				}

				vClient.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string Account_Number,string PinCode)
	{
		vector <clsBankClient> vClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == Account_Number && Client.PIN_CODE == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClient.push_back(Client);
			}

			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExiste(string Account_Number)
	{
		clsBankClient Client = clsBankClient::Find(Account_Number);
		return (!Client.IsEmpty());
	}
	
	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : vClients)
		{
			C._MarkforDelete = true;
			break;
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, FailedAccountNumberEsiste=2 };

	enSaveResult Save()
	{
		switch (_mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveResult::svFaildEmptyObject;
			break;
		case clsBankClient::UdpateMode:

			_Update();
			return enSaveResult::svSucceeded;
			break;

		case clsBankClient::AddNewMode:
			if (clsBankClient::IsClientExiste(_accountnumber))
			{
				return enSaveResult::FailedAccountNumberEsiste;
			}
			else
			{
				_AddNew();
				_mode = enMode::UdpateMode;
				return enSaveResult::svSucceeded;
			}
		
		default:
			break;
		}
	}
};

