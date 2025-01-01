#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include"clsBankClient.h";
#include"clsInputValidate.h";
#include"clsScreen.h";
class clsTotalBalanceScreen:protected clsScreen
{
     //vector<clsBankClient >info= clsBankClient:: GetClientsList();
	//double totalbalance = clsBankClient::GetTotalBalances();

	static void setclientsinfoscreen(clsBankClient c) {

		
			cout << setw(49) << left << "" <<"|" << c.FullName
		    <<"\t\t|"<< c.GetAccountBalance() << endl;

		

	}

public:
	static void totalbalancescreen() {

		vector<clsBankClient >info = clsBankClient::GetClientsList();
		double totalbalance = clsBankClient::GetTotalBalances();


		system("cls");
		_DrawScreenHeader("\t\tTransaction Screen");

		cout << setw(37) << left << "" << "=======================================================\n";
		cout << setw(37) << left << "" << "\t\t\tTotal Balance Screen\n";
		cout << setw(37) << left << "" << "=======================================================\n";
		cout << setw(49) << left << "" << "FullName\t\t" << "AccountBalance\n\n";

		for (clsBankClient c : info) {
			setclientsinfoscreen(c);
		}
		cout << setw(37) << left << "" << "=======================================================\n";

		cout << setw(37) << left << ""<<"TotalBalance: " << totalbalance;
	
	}

	
};

