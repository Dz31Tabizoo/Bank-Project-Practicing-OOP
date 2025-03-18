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
	enum enMode { EmptyMode = 0, UdpateMode = 1 };

	enMode _mode;
	string _accountnumber;
	string _pincode;
	float _accountbalance;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Separator = "#//#")
	{
		vector<string>vClient;
		vClient = clsStrings::Split(Line, Separator);

		return clsBankClient(enMode::UdpateMode, vClient[4], vClient[5], vClient[0], vClient[1], vClient[2], vClient[3], stod(vClient[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
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
	

};

