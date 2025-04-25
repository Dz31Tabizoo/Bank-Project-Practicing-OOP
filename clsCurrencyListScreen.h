#pragma once
#include"clsScreen.h"
#include "clsCurrency.h"
#include <ios>
#include <iomanip>
#include <iostream>

class clsCurrencyListScreen : public clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{

		cout << setw(8) << left << "" << "|" << setw(30) << left << Currency.GetCountry();
		cout << "| " << setw(8) << left << Currency.GetCurrencyCode();
		cout << "| " << setw(45) << left << Currency.GetCurrencyName();
		cout << "| " << setw(10) << left << Currency.RATE;
	}
 


public:

	static void ShowCurrencyListScreen()
	{
		vector <clsCurrency> vCurc;
		vCurc = clsCurrency::GetCurrenciesList();

		string title = "Currency List Screen";
		string Subtitle = "(" + to_string(vCurc.size()) + ") Currency (s)";
		_DrawScreenHeader(title, Subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		for ( const auto & C: vCurc)
		{
			_PrintCurrencyRecordLine(C);
			cout << endl;
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

	}




};

