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
	enum enMode{EmptyMode =0 , UdpateMode =1};

	enMode _mode;
	string _accountnumber;
	string _pincode;
	float _accountbalance;

public:
	clsBankClient(enMode mode, string accountnub, string pin, float accountbalance, string firstname, string lastname, string email, string phone) :clsPerson(firstname, lastname, email, phone)
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
			while (getline(MyFile,Line))
			{
				
			}


		}
	}
};

