#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "basket.h"
#include "listProduct.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <map>
#include "Interf.h"


using namespace std;

class Customer // покупець
{
protected:
	string name;
	string sekondName;
	string login;
	string rang;
	double sumOfchek;
	string password;
	basket* Basket;
	listProduct* listOfproduct;
public:
	Customer() : Customer("", "", "","") {};
	Customer(string login, string name, string sekondName,string password)
	{
		this->name = name;
		this->sekondName = sekondName;
		this->login = login;
		this->password = password;
		this->rang = "Usual";
		this->sumOfchek = 0;
		this->Basket = new basket();
		this->listOfproduct = new listProduct();
	}
	/*~Customer() {
		this->name.clear();
		this->sekondName.clear();
		this->login.clear();
		delete this->listOfproduct;
		delete this->Basket;
	}*/
	string getPassword() { return this->password; }
	void setname(string name) { this->name = name; }
	void setsekondName(string sekondName) { this->sekondName = sekondName; }
	void setlogin(string login) { this->login = login; }
	void setChek(double sumOfchek) { this->sumOfchek = sumOfchek; }
	string getname() { return this->name; }
	string getlogin() { return this->login; }
	double sumChek() { return this->sumOfchek; }
	friend ostream& operator <<(ostream& stream, Customer& custom) {
		stream << custom.name << " " << custom.sekondName << " " <<custom.rang<< endl;
		return stream;
	}
	void MakePurchase() {
		listOfproduct->ReadyProd();
		char choise;
		while (true) {
			system("cls");
			uint32_t position;
			cout << "\nList of product: " << endl;
			cout << endl;
			listOfproduct->PrintList();
			cout << "\nTo take a position(1-n): ";
			cin >> position;
			product pr = listOfproduct->getProduct(position);
			Basket->AddProduct(pr);
			Basket->ShowList();
			cout << "\nDo you want continue: (y/n)";
			cin >> choise;
			if (choise == 'n') {
				break;
			}
		}
		system("cls");
		Basket->ShowList();
		cout << "\n\t\t\tChek is: " << Basket->TotalSum(1) << "  uah" << endl;
		system("pause");
	}
};
class Vip:public Customer {

public:
	Vip() : Customer("","", "", "") {};
	Vip(string login, string name, string sekondName,string password)
	{
		this->name = name;
		this->sekondName = sekondName;
		this->login = login;
		this->password = password;
		this->rang = "VIP";
	}
	/*~Vip() {
		this->name.clear();
		this->sekondName.clear();
		this->login.clear();
		this->rang.clear();
	}*/
};

class listCustomers : public listProduct, public product, public Customer
{
private:
	map <string, Customer>* listCustomer;
	map <string, Vip>* listCustomerVip;
public:
	listCustomers() {
		listCustomer = new map <string, Customer >();
		listCustomerVip = new map <string, Vip >();
	}
	~listCustomers() {
		delete listCustomer;
		delete listCustomerVip;
	}
	void AddCustomer(string name, string sekondName, string login,string password) {
		Customer customer(name, sekondName, login,password);
		pair<string, Customer> custom(login, customer);
		listCustomer->insert(custom);
	}
	void AddCustomerVIP(string name, string sekondName, string login,string password) {
		Vip customer(name, sekondName, login,password);
		pair<string, Vip> custom(login, customer);
		listCustomerVip->insert(custom);
	}
	void PrintActive() {
		auto item = listCustomer->begin();
		cout << "\n\t\t\tCustomers" << endl;
		if (!listCustomer->empty()) {
			for (; item != listCustomer->end(); item++) {
				auto sum = item->second;
				if (sum.sumChek()) {
					cout << item->second << endl;
				}
			}
			cout << endl;
		}
		else {
			cout << "\nList is empty" << endl;
		}
	}
	Customer* FindCustom() {
		system("cls");
		string login;
		string password;
		cout << "\n\t\tInput data for sign in:" << endl;
		cout << endl;
		cout << "\n\t\t>login: ";
		cin >> login;
		cout << "\n\t\t>password: ";
		cin >> password;
		auto item = listCustomer->find(login);
		if (item==listCustomer->end() || item->second.getPassword() != password) {
			cout << "\n\t\tUncorrect data!" << endl;
			system("pause");
			FindCustom();
		}
		else {
			return &item->second;
		}
	}
	Vip* FindVip() {
		string login;
		string password;
		cout << "\n\t\tInput data for sign in:" << endl;
		cout << endl;
		cout << "\n\t\t>login: ";
		cin >> login;
		cout << "\n\t\t>password: ";
		cin >> password;
		auto item = listCustomerVip->find(login);
		if (item==listCustomerVip->end() || item->second.getPassword() != password) {
			cout << "\n\t\tUncorrect data!" << endl;
			system("pause");
			FindCustom();
		}
		else {
			return &item->second;
		}
	}
	void AddNewCustomer() {
		bool a = true;
		char choise;
		string name, sekondName;
		string rang;
		string login,password;
		while (a) {
			system("cls");
			cout << "\nEntering information for adding customer: " << endl;
			cout << "\n-name : ";
			cin >> name;
			cout << "\n-Sekond Name : ";
			cin >> sekondName;
			cout << "\n-login:";
			cin >> login;
			cout << "\n-rang(vip/not): ";
			cin >> rang;
			cout << "\n-password";
			cin >> password;
			auto item = this->listCustomer->find(login);
			auto itemVIP = this->listCustomerVip->find(login);
			if (item == this->listCustomer->end() && itemVIP == this->listCustomerVip->end()) {
				if (rang == "vip" || rang == "VIP" || rang == "Vip") {
					AddCustomerVIP(name, sekondName, login, password);
					return;
				}
				else {
					AddCustomer(name, sekondName, login, password);
					return;
				}
			}
			else {
				cout << "\n\t\tAccount exist!" << endl;
				system("pause");
			}
		}
	}
			
	
	void TestCustomer() {
		const int N = 5;
		Customer p1("7777", "Max", "Sharf","");
		Customer p2("12341" ,"Vova", "Note","");
		Customer p3("8887","Grisha", "Dada","");
		Customer p4("66666", "Nastia", "Mirnay","");
		Customer p5("28888","Andegraynt", "Jojo","");
		pair<string, Customer> prod[N] = {
		{"7777",p1},
		{"12341",p2},
		{"8887",p3},
		{"66666",p4},
		{"28888",p5},
		};
		for (size_t i = 0; i < N; i++) {
			listCustomer->insert(prod[i]);
		}
	}
	void PrintListCustomer() {
		auto item = listCustomer->begin();
		cout << "\n\t\t\tCustomers" << endl;
		if (item!= listCustomer->end()) {
			for (; item != listCustomer->end(); item++) {
				cout << item->first << ": " << item->second << endl;
			}
			cout << endl;
		}
		else {
			cout << "\nList is empty" << endl;
		}
	}
	void PrintVIP() {
		auto item = listCustomerVip->begin();
		cout << "\n\t\t\tVIP" << endl;
		cout << endl;
		if (!listCustomer->empty()) {
			for (; item != listCustomerVip->end(); item++) {
				cout <<item->second << endl;
			}
			cout << endl;
		}
		else {
			cout << "\nList is empty" << endl;
		}
	}
	void PrintAll() {
		PrintListCustomer();
		PrintVIP();
	}
	Customer* getCustomer(string login) {
		auto item = this->listCustomer->find(login);
		Customer* tmp = &item->second;
		if (tmp) {
			return tmp;
		}
		else
		{
			return nullptr;
		}
	}
	void DelCustm(string login) {
		map <string, Customer>::iterator it;
		it = listCustomer->find(login);
		if (it!=listCustomer->end()){
			listCustomer->erase(login);
		}
		else {
			cout << "\nValue is not found!" << endl;
		}
	}
};
