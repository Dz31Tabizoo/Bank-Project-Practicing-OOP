#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
private:
	string _firstname;
	string _lastname;
	string _email;
	string _phone;

public:
	// constructor 
	clsPerson(string firstNm,string lastNm,string eMl,string phon ) 
	{
		_firstname = firstNm;
		this->_lastname = lastNm;
		this->_email = eMl;
		_phone = phon;
	}
	//Properties
	void SetFirstname(string FirstName)
	{
		this->_firstname = FirstName;
	}
	string GetFirstName()
	{
		return this->_firstname;
	}

	__declspec(property(get = GetFirstName, put = SetFirstname)) string Firstname;

	void SetLastName(string LastName)
	{
		_lastname = LastName;
	}
	string GetLastName()
	{
		return _lastname;
	}

	__declspec(property(get = GetLastName, put = SetLastname)) string Lastname;

	void SetEmail(string Email)
	{
		_email = Email;
	}
	string GetEmail()
	{
		return _email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;
	void SetPhone(string phone)
	{
		this->_phone = phone;
	}
	string GetPhone()
	{
		return this->_phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;
	string FullName()
	{
		return _firstname + " " + _lastname;
	}

};

