#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h";
#include "String.h";
#include <vector>
#include <fstream>
#include"clsString.h";
#include"globalobject.h";

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;


    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;



    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

  static string _Transfer_transferringinfo_to_line(clsBankClient& client1, clsBankClient& client2,
      float& amount) {

        return client1.AccountNumber() + "/#" + client2.AccountNumber() + "/#" + to_string(amount) +
            "/#" + to_string(client1.AccountBalance) + "/#" + to_string(client2.AccountBalance) + "/#" + User.FullName;


    }

   static void _Save_Transfer(clsBankClient& client1, clsBankClient& client2,
        float& amount) {
        string info = _Transfer_transferringinfo_to_line(client1, client2,amount);
        fstream MYFILE;
        MYFILE.open("Transfer.txt", ios::out | ios::app);
        if (MYFILE.is_open()) {
            MYFILE << info << endl;

        }
        MYFILE.close();
    }



    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }
    string setAccoutNumber(string code) {
        _AccountNumber = code;
    }
    string AccountNumber()
    {
        return _AccountNumber;
    }
     //__declspec(property(get = GetAccountNumber, put = setAccoutNumber)) string AccountNumber;

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    /*
       No UI Related code iside object.
     void Print()
     {
         cout << "\nClient Card:";
         cout << "\n___________________";
         cout << "\nFirstName   : " << FirstName;
         cout << "\nLastName    : " << LastName;
         cout << "\nFull Name   : " << FullName();
         cout << "\nEmail       : " << Email;
         cout << "\nPhone       : " << Phone;
         cout << "\nAcc. Number : " << _AccountNumber;
         cout << "\nPassword    : " << _PinCode;
         cout << "\nBalance     : " << _AccountBalance;
         cout << "\n___________________\n";

     }*/

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }
    static bool Checkifvalidprice(clsBankClient client, int balance) {
        return (client.AccountBalance >= balance);
    }



    static bool Transfer(clsBankClient client1, clsBankClient client2, float balance) {
        vector<clsBankClient>vclients = _LoadClientsDataFromFile();
        int a = 0;
        if (!IsClientExist(client1._AccountNumber)) {
            return 0;
        }
        else if (!IsClientExist(client1._AccountNumber)) {
            return 0;
        }

        for (clsBankClient& c : vclients) {
            if (c.AccountNumber() == client1.AccountNumber()) {
                c._AccountBalance -= balance;
                client1._AccountBalance -= balance;
                a += 1;
            }
            if (c.AccountNumber() == client2.AccountNumber()) {
                c._AccountBalance += balance;
                client2._AccountBalance += balance;
                a += 1;
            }
            if (a == 2) {
                _SaveCleintsDataToFile(vclients);
                _Save_Transfer(client1, client2, balance);
                return true;
                break;
            }
        }
        return 0;

    }

 



    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {
            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }




    static bool Deposit(string &accountnumber,float amount) {

        vector<clsBankClient>clients = _LoadClientsDataFromFile();
        for (clsBankClient& c : clients) {
            if (c._AccountNumber == accountnumber) {
               c._AccountBalance += amount;
               _SaveCleintsDataToFile(clients);
               return true;
               break;
            }
        }
        return false;
    }
    static bool withdraw(string& accountnumber, float amount) {
        vector<clsBankClient>clients = _LoadClientsDataFromFile();
        for (clsBankClient& c : clients) {
            if (c._AccountNumber == accountnumber) {
                c._AccountBalance -= amount;
                _SaveCleintsDataToFile(clients);
                return true;
                break;
            }
        }
        return false;


    }
    
};
