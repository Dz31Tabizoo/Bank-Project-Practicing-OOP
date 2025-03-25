#pragma once
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:

	static void GetDate(clsDate Date)
	{
		cout << setw(37) << left << "" << "\t\t ";
		Date.Print();
	}

	static void _DrawScreenHeader(string Title,string Subtitle="")
	{
		cout << setw(37) << left <<"" << "***********************************" << endl;
		cout << setw(37) << left <<"" << "\t\t" << Title << endl;
		if (Subtitle != "")
		{
			cout << setw(37) << left << "" << "\t" << Subtitle << endl;
		}
		clsDate Date;
		 GetDate(Date);
		cout << setw(37) << left <<"" << "___________________________________" << endl;
	}



};

