#pragma once
#include "clsCurrency.h"
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidation.h"



class clsCurrencyFindScreen : public clsScreen
{

	static void _PrintCurrencyData(clsCurrency Cur)
	{
		Cur.Print();
	}


public:

	static void ShowFindCurrencyScreen()
	{
		string CodeOrName;
		
			short Answer;
		cout << "\nDo You Want to search By Country Or By Code ? [1]/[2]";
		Answer = clsInputValidation::ReadshortBetween("Wrong Answer... try again ", 1, 2);
		if (Answer == 1)
		{
			cout << "\nEnter the Country of Currency to Search: ";
			CodeOrName = clsInputValidation::ReadString();
			clsCurrency Cur = clsCurrency::FindByCountry(CodeOrName);
			_PrintCurrencyData(Cur);
		}
		else
		{
			cout << "\nEnter the Code of Currency to Search: ";
			CodeOrName = clsInputValidation::ReadString();
			clsCurrency Cur = clsCurrency::FindByCode(CodeOrName);
			_PrintCurrencyData(Cur);
		}
	}


};

