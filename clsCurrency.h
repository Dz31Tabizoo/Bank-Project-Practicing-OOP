#pragma once
#include <iostream>
#include <string>
#include "string.h"
#include <vector>
#include <fstream>

using namespace std;

class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode=1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	


public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) : _Mode(Mode), _Country(Country), _CurrencyCode(CurrencyCode), _CurrencyName(CurrencyName), _Rate(Rate) {}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetCountry()
	{
		return _Country;
	}
	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}
	string GetCurrencyName()
	{
		return _CurrencyName;
	}
	void UpdateRate(float x)
	{
		_Rate = x;
		///to fill with update functions
	}

	float GetRate()
	{
		return _Rate;
	}
	
};

