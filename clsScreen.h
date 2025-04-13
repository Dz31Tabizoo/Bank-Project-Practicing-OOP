#pragma once
#include "clsDate.h"
#include "Global.h"
#include "clsUser.h"
#include <iostream>
#include <iomanip>

using namespace std;

class clsScreen
{
protected:

	static void GetDate(clsDate Date)
	{
		cout << setw(37) << left << "\n" ;
		cout << "Date: "; Date.Print();
	}
	static void PrintCurrrentUser()
	{
		
		cout << setw(36) << left << "" ;
		cout << "User: " << CurrentUser.USERNAME << endl;
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
		 PrintCurrrentUser();
		cout << setw(37) << left <<"" << "___________________________________" << endl;
	}

	static bool CheckAccessRights(clsUser::enPermissions permission)
	{
		if (!CurrentUser.CheckAccessPermission(permission))
		{
			cout << "\n\t\t\t\t ---------------------------------------";
			cout << "\n\n\t\t\t\t  ACCESS DENIED! CONTACT ADMIN";
			cout << "\n\t\t\t\t ---------------------------------------";
			return false;
		}
		else
		{
			return true;
		}
	}


};

