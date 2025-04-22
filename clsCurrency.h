#pragma once
#include <iostream>
#include <string>
#include "string.h"
#include <vector>
#include <fstream>
#include "Strings.h"


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



	static clsCurrency _ConvertLineToCurrencyObj(string _Line)
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsStrings::Split(_Line, "#//#");

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], std::stof(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToString(clsCurrency Crnc, string Separator = "#//#")
	{
		string stCurrencyRecord = "";
		stCurrencyRecord += Crnc.GetCountry() + Separator;
		stCurrencyRecord += Crnc.GetCurrencyCode() + Separator;
		stCurrencyRecord += Crnc.GetCurrencyName() + Separator;
		stCurrencyRecord += to_string(Crnc.RATE);

		return stCurrencyRecord;
	}

	static vector <clsCurrency> _LoadCurancysDataFromFile()
	{
		vector <clsCurrency> vCurrencys;
		fstream Myfile;

		Myfile.open("Currencies.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObj(Line);
				vCurrencys.push_back(Currency);
			}
			Myfile.close();
		}
		return vCurrencys;
	}

	static void	_SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::out); //Overwrite

		string DataLine;
		if (Myfile.is_open())
		{
			for (const auto& C : vCurrencys)
			{
				DataLine = _ConvertCurrencyObjectToString(C);
				Myfile << DataLine << endl;
			}
			Myfile.close();
		}
	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurancysDataFromFile();

		for (auto& C : _vCurrencys)
		{
			if (C.GetCurrencyCode() == GetCurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(_vCurrencys);

	}

	static clsCurrency _GetEmptyObj()
	{
		return clsCurrency(clsCurrency::enMode::EmptyMode, "", "", "", 0);
	}


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
		_Update();
	}
	float GetRate()
	{
		return _Rate;
	}
	__declspec(property(get = GetRate, put = UpdateRate))float RATE;

	static clsCurrency FindByCode(string Currency_Code)
	{
		Currency_Code = clsStrings::UpperAllString(Currency_Code);

		fstream Myfile;
		string DataLine;
		Myfile.open("Currencises.txt", ios::in);
		if (Myfile.is_open())
		{
			while (getline(Myfile, DataLine))
			{
				clsCurrency Obj = _ConvertLineToCurrencyObj(DataLine);
				if (clsStrings::UpperAllString(Obj.GetCurrencyCode())== Currency_Code)
				{
					Myfile.close();
					return Obj;
				}
				else
				{
					Myfile.close();
					return _GetEmptyObj();

				}

			}
		}	
	}

	static clsCurrency FindByCountry(string Currency_Country)
	{
		Currency_Country = clsStrings::UpperAllString(Currency_Country);

		fstream Myfile;
		string DataLine;
		Myfile.open("Currencises.txt", ios::in);
		if (Myfile.is_open())
		{
			while (getline(Myfile, DataLine))
			{
				clsCurrency Obj = _ConvertLineToCurrencyObj(DataLine);
				if (clsStrings::UpperAllString(Obj.GetCountry()) == Currency_Country)
				{
					Myfile.close();
					return Obj;
				}
				else
				{
					Myfile.close();
					return _GetEmptyObj();
				}

			}
		}
	}

	static bool IsCurrencyExiste(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurancysDataFromFile();
	}
};

