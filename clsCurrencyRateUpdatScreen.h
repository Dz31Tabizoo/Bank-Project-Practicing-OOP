#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsCurrency.h"

class clsCurrencyRateUpdatScreen : public clsScreen
{
	static float _ReadCurrencyRate()
	{
		float NewRate = 0;
		printf("/n Enter New Rate: ");
		cin >> NewRate;
		return NewRate;
	}


public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("Currency Update Screen");

		string CurrencyCode = "";

		cout << "\nEnter Currency Code: ";
		CurrencyCode = clsInputValidation::ReadString();

		while (!clsCurrency::IsCurrencyExiste(CurrencyCode))
		{
			cout << "\nCode dosn't Existe: ";
			CurrencyCode = clsInputValidation::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		Currency.Print();

		cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n ----- Updating Currency Rate: -------------";

			Currency.UpdateRate(_ReadCurrencyRate());

			cout << "\n Currency Rate Successfully :)" << endl;
			Currency.Print();
		}



	}





};

