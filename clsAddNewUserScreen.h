#pragma once
#include<vector>
#include<iomanip>
#include"clsBankUser.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<string>
class clsAddNewUserScreen:protected clsScreen
{

    static void CheckChar(char &answer) {
        while (1){
            if (toupper(answer) != 'Y' && toupper(answer) != 'N') {
                cout << "please answer with either [Y or N]\n";
                cin >> answer;
            }
            else {
                break;
            }
        }

    }
    static void _ReadUserAccesses(clsBankUser& User) {
        short countaccess=0;
       char answer;
        cout << "\ndo you want the user to get access to Show Client List [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions |= 1;
        }

        cout << "do you want the user to get access to Add New Client Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions |= 2;
        }

        cout << "do you want the user to get access to Delete Client Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions |= 4;
        }

        cout << "do you want the user to get access to Update Client Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions |= 8;
        }

        cout << "do you want the user to get access to Find Client Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions |= 16;
        }

        cout << "do you want the user to get access to Transaction Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions |= 32;
        }
        cout << "do you want the user to get access to Manage Users Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions |= 64;
        }
        cout << "do you want the user to get access to User Register Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions |= 128;
        }
        cout << "do you want the user to get access to Currency Exchange Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions |= 256;
        }
        User.Save();
    }
    static void _ReadUserInfo(clsBankUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();
        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();
        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();
        _ReadUserAccesses(User);
    }

	static void _askforuserinfo() {
		string code;
		cout << "enter the user code\n";
		code = clsInputValidate::ReadString();
		while (clsBankUser::IsUsertExist(code)) {
			cout << "User already exist please enter another code\n";
			code = clsInputValidate::ReadString();
		}
		clsBankUser User = clsBankUser::GetAddNewClientObject(code);
        _ReadUserInfo(User);
	}

public:
    static void ShowAddNewUserScreen() {
        system("cls");
        _DrawScreenHeader("\t\tAdd New User Screen");
        _askforuserinfo();
    }
};

