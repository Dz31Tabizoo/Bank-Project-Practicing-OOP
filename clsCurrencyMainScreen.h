#pragma once
#include"clsScreen.h"
#include<iostream>
#include<string>
#include<iomanip>
#include "clsInputValidation.h"
#include "clsCurrencyListScreen.h"
#include "clsCurrencyFindScreen.h"
#include "clsCurrencyRateUpdatScreen.h"


class clsCurrencyMainScreen : public clsScreen
{
private:
	enum _enMenu {enCurrencyListe = 1, enFindCureency=2,enUpdateCurrency=3,enCurrencyCalculator=4,enMainMenue=5 };

	static void GoBackToCurrencyMainMenu()
	{
		cout << "\nPress Eny Key To Goback to Main Menue...";
		system("pause>0");
		ShowCurrencyMainMenue();
	}

	static void _ShowCurrencyRateScreenUpdate()
	{
		system("cls");
		clsCurrencyRateUpdatScreen::ShowUpdateCurrencyRateScreen();
		GoBackToCurrencyMainMenu();
	}

	static void _ShowFindCurScreen()
	{
		system("cls");
		clsCurrencyFindScreen::ShowFindCurrencyScreen();
		GoBackToCurrencyMainMenu();
	}

	static void _ShowCurrencyListScreen()
	{
		system("cls");
		clsCurrencyListScreen::ShowCurrencyListScreen();
		GoBackToCurrencyMainMenu();
	}

	static void _PerformCurrencyMenueOptions(_enMenu Options)
	{
		switch (Options)
		{
		case clsCurrencyMainScreen::enCurrencyListe:

			_ShowCurrencyListScreen();
			
			break;

		case clsCurrencyMainScreen::enFindCureency:

			_ShowFindCurScreen();

			break;

		case clsCurrencyMainScreen::enUpdateCurrency:

			_ShowCurrencyRateScreenUpdate();

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

