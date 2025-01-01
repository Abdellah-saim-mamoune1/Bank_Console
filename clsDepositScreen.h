#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include"clsBankClient.h";
#include"clsInputValidate.h";
#include"clsScreen.h";
#include<limits>
class clsDepositScreen:protected clsScreen
{
	static void _printclientinfo(clsBankClient &client) {
		cout << "\nClient Balance:";
		cout << "\n_________________________";
		cout << "\nFull Name   : " << client.FullName;
		cout << "\nBalance     : " << client.AccountBalance;
		cout << "\n_________________________\n\n";
	}
	
	static float _clientdepositcontity() {
		float _contity;
		cout << "how much do you want to deposit , maximen amount possible: [100000]\n";
		cin >> _contity;
		while (_contity < 0 || _contity>100000 || cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "error please enter a valid amount\n";
			cin >> _contity;
		}
		return _contity;
	}


public:
	static void depositing() {
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tDeposit Screen");

		string _accountnumber;
		cout << "enter account number\n";
		_accountnumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(_accountnumber)) {
			cout << "client was not found please enter a valid account number\n";
			cin >> _accountnumber;
		}
		clsBankClient client = clsBankClient::Find(_accountnumber);
		_printclientinfo(client);
		if (clsBankClient::Deposit(_accountnumber, _clientdepositcontity())) {
			cout << "Deposit Process went Successfuly\n";

		}
		else {
			cout << "Deposit Process Failed\n";
		}

	}
};

