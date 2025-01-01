#pragma once
#include<vector>
#include<iomanip>
#include"clsBankUser.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<string>
class clsUpdateUserScreen:clsScreen
{
    static void CheckChar(char& answer) {
        while (1) {
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
        short countaccess = 0;
        char answer;
        cout << "\ndo you want the user to get access to Show Client List [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions += 1;
        }

        cout << "do you want the user to get access to Add New Client Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions += 2;
        }

        cout << "do you want the user to get access to Delete Client Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions += 4;
        }

        cout << "do you want the user to get access to Update Client Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions += 8;
        }

        cout << "do you want the user to get access to Find Client Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions += 16;
        }

        cout << "do you want the user to get access to Transaction Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions += 32;
        }
        cout << "do you want the user to get access to Manage Users Screen [Y/N] ?\n";
        cin >> answer;
        CheckChar(answer);
        if (toupper(answer) == 'Y') {
            User.Permissions += 64;
        }
        User.Save();
    }

    static void _PrintUserInfo(clsBankUser User) {
        cout << "\nUser Card:";
        cout << "\n___________________________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName;
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nAccess      : " << User.Permissions;
        cout << "\n___________________________________\n";
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
        char Answer;
        cout << "enter the user code\n";
        code = clsInputValidate::ReadString();
        while (!clsBankUser::IsUsertExist(code)) {
            cout << "User Doesn't exist please enter another code\n";
            code = clsInputValidate::ReadString();
        }
        clsBankUser User = clsBankUser::Find(code);
        _PrintUserInfo(User);
        cout << "\ndo you realy want to Update This User Informations [Y/N]?\n";
        cin >> Answer;
        CheckChar(Answer);
        if (toupper(Answer == 'Y')) {
            _ReadUserInfo(User);
        }
    }

public:
    static void ShowUpdateUserScreen() {
        system("cls");
        _DrawScreenHeader("\t\tUpdate User Screen");
        _askforuserinfo();
    }


};

