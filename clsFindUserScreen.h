#pragma once
#include<vector>
#include<iomanip>
#include"clsBankUser.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<string>
class clsFindUserScreen:clsScreen
{
   
	static void _PrintUserInfo(clsBankUser& User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName;
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.GetPhone();
		cout << "\nAccess      : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:
	static void ShowFindUserScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tFind User Screen");
		string code;
		cout << "enter the user code\n";
		code = clsInputValidate::ReadString();
		while (!clsBankUser::IsUsertExist(code)) {
			cout << "User Doesn't exist please enter another code\n";
			code = clsInputValidate::ReadString();
		}
		clsBankUser User = clsBankUser::Find(code);
		_PrintUserInfo(User);
	}


};

