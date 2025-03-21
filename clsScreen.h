#pragma once

using namespace std;

class clsScreen
{
protected:


	static void _DrawScreenHeader(string Title,string Subtitle="")
	{
		cout << setw(37) << left <<"" << "*********************************" << endl;
		cout << setw(37) << left <<"" << "\t\t" << Title << endl;
		cout << setw(37) << left <<"" << "_________________________________" << endl;
	}



};

