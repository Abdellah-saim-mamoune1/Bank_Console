#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsString.h";
using namespace std;
class clsCurrency
{
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	enum enMode { EmptyMode = 0, UpdateMode = 1/*, AddNewMode = 2 */ };
	enMode _Mode;
	clsCurrency() {};
	clsCurrency(enMode mode,string countryname, string currencycode, string currencyname, float rate) {
		_Country = countryname;
		_CurrencyCode = currencycode;
		_CurrencyName = currencyname;
		_Rate = rate;
		_Mode = mode;
	}

	static clsCurrency _ConvertLinetoCurrencyObject(string &Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);
		return clsCurrency(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], stof(vClientData[3]));

	}


	static string _ConvertCurrencyObjectToLine(clsCurrency vcurrencys, string Seperator = "#//#")
	{

		string stUsertRecord = "";
		stUsertRecord += vcurrencys.Country() + Seperator;
		stUsertRecord += vcurrencys.CurrencyCode() + Seperator;
		stUsertRecord += vcurrencys.CurrencyName() + Seperator;
		stUsertRecord += to_string(vcurrencys.Rate);
		return stUsertRecord;

	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vcurrencys)
	{

		fstream MyFile;
		MyFile.open("Currency.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency& C : vcurrencys)
			{
				
					//we only write records that are not marked for delete.  
					DataLine = _ConvertCurrencyObjectToLine(C);
					MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}

	static vector<clsCurrency> _LoadCurrencysDataFromFile() {
		fstream MYFILE;
		vector<clsCurrency>vCurrency;
		clsCurrency currency;
		MYFILE.open("Currency.txt", ios::in);
		string info;
		if (MYFILE.is_open()) {
			while (getline(MYFILE, info)) {
				currency = _ConvertLinetoCurrencyObject(info);
				vCurrency.push_back(currency);
			}
		}
		MYFILE.close();
		return vCurrency;
	}
	
	static clsCurrency _GetEmptyObject() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
	bool _IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

public:
	
	


	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrencysDataFromFile();

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float GetRate()
	{
		return _Rate;
	}
	void SetRate(float rate) {
		_Rate = rate;
	}
	__declspec(property(get = GetRate, put = SetRate)) float Rate ;




	static clsCurrency FindByCode(string code) {
		code = clsString::UpperAllString(code);
		vector< clsCurrency>vcurrency;
		vcurrency = _LoadCurrencysDataFromFile();
		for (clsCurrency& c : vcurrency) {
			if (c._CurrencyCode == code) {
				return c;
			}
		}
		return _GetEmptyObject();
	}



	static clsCurrency FindByName(string Name) {
		Name = clsString::UpperFirstLetter_Lowerelse(Name);
		vector< clsCurrency>vcurrency;
		vcurrency = _LoadCurrencysDataFromFile();
		for (clsCurrency& c : vcurrency) {
			if (c.Country() == Name) {
				return c;
			}
		}
		return _GetEmptyObject();
	}



	 static bool Is_Country_ExistBy_C(string code) {
		 clsCurrency country = FindByCode(code);
		 return (!country._IsEmpty());
	}

	 static bool Is_Country_ExistBy_N(string Name) {
		 clsCurrency country = FindByName(Name);
		 return (!country._IsEmpty());
	 }

	 void _Update()
	 {
		 vector <clsCurrency> vCurrencys;
		 vCurrencys = _LoadCurrencysDataFromFile();

		 for (clsCurrency& C : vCurrencys)
		 {
			 if (C.CurrencyCode() == _CurrencyCode)
			 {
				 C = *this;
				 break;
			 }
		 }

		 _SaveCurrencyDataToFile(vCurrencys);

	 }

	 float CurrencyCalculator_FromUSDto(float Amount) {
		 return Amount *this->Rate;
	 }
	 float CurrencyCalculator_ToUSD(float Amount) {
		 return Amount /this->Rate;
	 }

};

