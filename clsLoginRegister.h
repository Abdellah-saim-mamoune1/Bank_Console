#pragma once
#include<iostream>
#include"clsBankUser.h";
#include"clsScreen.h";
#include<vector>
#include<iomanip>
using namespace std;
class clsLoginRegister:protected clsScreen
{
	static void _printinfo(clsBankUser &c) {
		
		cout << setw(15) << left << "" << "| "
			<< setw(20) << left << c.code
			<< "| " << setw(30) << left << c.FullName
			<< "| " << setw(11) << left << c.Permissions
			<< "|\n";
	}
public:
	static void showloginregisterscreen() {
		vector<clsBankUser>vUsers = clsBankUser::load_login_register();
		system("cls");
		_DrawScreenHeader("\t\tLOGIN REGISTER SCREEN");

        cout << setw(16) << "" << "===================================================================\n";
        cout << setw(16) << "" << "\t\t\tLOGIN REGISTER SCREEN\n";
        cout << setw(16) << "" << "===================================================================\n";

        // Column headers
        cout << setw(15) << left << "" << "| "
            << setw(20) << left << "Code"
            << "| " << setw(30) << left << "Full Name"
            << "| " << setw(9) << left << "Permissions"
            << "|\n";
        cout << setw(15) << left << "" << "--------------------------------------------------------------------\n";

        // Print each user's info
        for (clsBankUser c : vUsers) {
            _printinfo(c);
        }

        // Footer line
        cout << setw(15) << "" << "====================================================================\n";
    }


};

