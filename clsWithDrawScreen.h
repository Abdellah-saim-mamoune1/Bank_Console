#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include"clsBankClient.h";
#include"clsInputValidate.h";
#include"clsScreen.h";
#include<limits>
class clsWithDrawScreen :protected clsScreen
{
	static void _printclientinfo(clsBankClient& client) {
		cout << "\nClient Balance:";
		cout << "\n_________________________";
		cout << "\nFull Name   : " << client.FullName;
		cout << "\nBalance     : " << client.AccountBalance;
		cout << "\n_________________________\n\n";
	}

	static float _ClientWithDrawAmount(const float &amount) {
		float _contity;
		cout << "how much do you want to withdraw , maximen amount must not be upper than account amount\n";
		cin >> _contity;
		while (_contity < 0 || _contity>amount || cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "error please enter a valid amount\n";
			cin >> _contity;
		}
		return _contity;
	}


public:
	static void withdrawingscreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tWithDraw Screen");

		string _accountnumber;
		cout << "enter account number\n";
		_accountnumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(_accountnumber)) {
			cout << "client was not found please enter a valid account number\n";
			cin >> _accountnumber;
		}
		clsBankClient client = clsBankClient::Find(_accountnumber);
		_printclientinfo(client);
		if (clsBankClient::withdraw(_accountnumber, _ClientWithDrawAmount(client.GetAccountBalance()))) {
			cout << "Withdraw Process went Successfuly\n";

		}
		else {
			cout << "WithDraw Process Failed\n";
		}

	}
};


