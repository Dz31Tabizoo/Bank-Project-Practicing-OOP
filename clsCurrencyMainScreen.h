#pragma once
#include"clsScreen.h"
#include<iostream>
#include<string>
#include<iomanip>
#include "clsInputValidation.h"


class clsCurrencyMainScreen : public clsScreen
{
private:
	enum _enMenu {enCurrencyListe = 0, enFindCureency=1,enUpdateCurrency=2,enCurrencyCalculator=3,enMainMenue=4 };



	static void _PerformCurrencyMenueOptions(_enMenu Options)
	{
		switch (Options)
		{
		case clsCurrencyMainScreen::enCurrencyListe:
			
			break;

		case clsCurrencyMainScreen::enFindCureency:

			break;

		case clsCurrencyMainScreen::enUpdateCurrency:

			break;

		case clsCurrencyMainScreen::enCurrencyCalculator:

			break;

		case clsCurrencyMainScreen::enMainMenue:

			break;

		
		}

	}

	static short _ReadCurrencyMainMenueOptions()
	{
		cout << setw(38) << "" << "Choose What you want to do [1] to [5]:\n";
		short Choise = clsInputValidation::ReadshortBetween("\t\t\t\tWrong Choise, Please select your choise from 1 to 5:\n", 1, 5);
		return Choise;
	}

public:

	static void ShowCurrencyMainMenue()
	{
		system("cls");
		_DrawScreenHeader("Currency Exchange Menue");

		cout << setw(38) << left << "" << "================================" << endl;
		cout << setw(38) << left << "" << "\tCurrency Main Menue\n";
		cout << setw(38) << left << "" << "================================" << endl;
		cout << setw(38) << left << "" << "\t[1] List Currencys. \n";
		cout << setw(38) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(38) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(38) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(38) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(38) << left << "" << "--------------------------------\n";
		                                   
		_PerformCurrencyMenueOptions(_enMenu(_ReadCurrencyMainMenueOptions()));
		
	}







};

