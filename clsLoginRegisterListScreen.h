#pragma once

#include "clsScreen.h"
#include "clsUser.h"

class clsLoginRegisterListScreen : public clsScreen
{
private:

	static void _PrintOneLoginRecord(clsUser::stLoginRegisterRecords Loginrecords)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << Loginrecords.Time;
		cout << "| " << setw(20) << left << Loginrecords.UserName;
		cout << "| " << setw(20) << left << Loginrecords.Password;
		cout << "| " << setw(10) << left << Loginrecords.Permission;

	}

public:

	static void LogInRegisterList()
	{
		vector <clsUser::stLoginRegisterRecords> vLoginRegisterRecords = clsUser::GetLoginRegisterLiset();

		string ss = "LogIn Register Liste Screen";
		string s = "( "+to_string (vLoginRegisterRecords.size())+" )"+" Log(s)";

		_DrawScreenHeader(ss, s);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisterRecords.size() == 0)
		{
			cout << "\t\t\t No Logins Avalable In The System!";
		}
		else
		{
			for (const auto& X : vLoginRegisterRecords)
			{
				_PrintOneLoginRecord(X); cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}




};

