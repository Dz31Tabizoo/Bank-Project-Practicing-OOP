#pragma once
#include "clsDate.h"
#include <iostream>
#include <string>
#include"Strings.h"

class clsInputValidation 
{
public:

	static bool IsNumberBetween(int number, int Limite1, int Limite2)
	{
		return (number >= Limite1 && number <= Limite2);
	}

	static bool IsNumberBetween(short number, short Limite1, short Limite2)
	{
		return (number >= Limite1 && number <= Limite2);
	}

	static bool IsNumberBetween(double number, double Limite1, double Limite2)
	{
		return (number >= Limite1 && number <= Limite2);
	}
	static bool IsNumberBetween(float number,float Limite1, float Limite2)
	{
		return (number >= Limite1 && number <= Limite2);
	}


	static bool IsDateBetween(clsDate date, clsDate from, clsDate to)
	{
		if ((clsDate::IsDate1AfterDate2(date,from) || clsDate::IsDate1EqualDate2(date,from)) && (clsDate::IsDate1BeforeDate2(date,to) || clsDate::IsDate1EqualDate2(date,to) )  )
		{
			return true;
		}

		if ((clsDate::IsDate1AfterDate2(date, to) || clsDate::IsDate1EqualDate2(date, to)) && (clsDate::IsDate1BeforeDate2(date, from) || clsDate::IsDate1EqualDate2(date, from)))
		{
			return true;
		}


		return false;

	}


	static int ReadIntNumber(string ErrorMessage="Invalide input, Please Enter egain\n")
	{
		int x;
		
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return x;
	}

	static double ReadDoubleNumber(string ErrorMessage)
	{
		double x;

		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return x;
	}

	static int ReadIntBetween(string ErrorMessage, int from, int to)
	{
		int x = ReadIntNumber();

		while (!IsNumberBetween(x, from, to))
		{
			cout << ErrorMessage;
			x = ReadIntNumber();
		}
		return x;

	}

	static double ReadDoubleBetween(string ErrorMessage, double from, double to)
	{
		double x = ReadDoubleNumber();

		while (!IsNumberBetween(x, from, to))
		{
			cout << ErrorMessage;
			x = ReadDoubleNumber();
		}
		return x;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
};

