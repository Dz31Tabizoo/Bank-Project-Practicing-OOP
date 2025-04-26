#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"


class clsCurrenciesCalculator : public clsScreen
{






public:
	static void ShowCurresnciesCalculatorScreen()
	{
		_DrawScreenHeader("Currencies Calculator");
		
		string CurrencyCode1, CurrencyCode2;
		cout << "\nEnter First Currency Code:";
		CurrencyCode1 = clsInputValidation::ReadString();
		cout << "\nEnter Second Currency Code:";
		CurrencyCode2 = clsInputValidation::ReadString();

		while (!clsCurrency::IsCurrencyExiste(CurrencyCode1)||clsCurrency::IsCurrencyExiste(CurrencyCode2))
		{
			system("cls");

			_DrawScreenHeader("Currencies Calculator");
			cout << "\nError Input:";
			cout << "\nEnter First Currency Code:";
			CurrencyCode1 = clsInputValidation::ReadString();
			cout << "\nEnter Second Currency Code:";
			CurrencyCode2 = clsInputValidation::ReadString();

		}
		clsCurrency Cur1 = clsCurrency::FindByCode(CurrencyCode1);
		clsCurrency cur2 = clsCurrency::FindByCode(CurrencyCode2);
		
		

	}





};

