#pragma once
#include<iostream>
#include"clsBankUser.h";
//#include"clsMainScreen.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"globalobject.h";
class clsLogOutScreen:protected clsScreen
{
private:
	//static clsBankUser User1;
	static bool  askuser() {
	   string code;
	   short a = 2;
	   cout << "please enter the user code\n";
	   code = clsInputValidate::ReadString();
	   while ((a > 0)&& (!clsBankUser::IsUsertExist(code))) {
			   cout << "User doesn't exist please enter another valid code\n";
			   cout << "you have " << a << " trys left\n";
			   code = clsInputValidate::ReadString();
			   a--;
		   }

	   if (!clsBankUser::IsUsertExist(code)) {
		   cout << "you are locked after 3 failed attempts";
		   return false;
	   }
	   else {
		   User = clsBankUser::Find(code);
		   User.save_login();
		   cout << "welcom " << User.FullName << endl;
		   //User1 = User;
		   system("pause");
		   system("cls");
		   return true;
	   }
		
	}
public:
	static bool ManageUsersScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tManage Users Screen");
		return askuser();
	}
	
};

