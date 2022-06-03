#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "listProduct.h"
#include "basket.h"
#include "Interf.h"

using namespace std;

class Employee
{
protected:
	string name;
	string surname;
	string rang;
	string password;
	uint32_t discount;
	basket* Basket;
	listProduct* listOfproduct;
	string login;
	
  public:
	  Employee(string name, string surname, string password,string login) {
		  this->name = name;
		  this->password = password;
		  this->rang = "employee";
		  this->login = login;
		  this->surname = surname;
		  this->discount = 10;
		  this->Basket = new basket();
		  this->listOfproduct = new listProduct();
	  }
	  Employee() :Employee("", "", "","") {};
	  /*~Employee() {
		  this->name.clear();
		  this->password.clear();
		  this->rang.clear();
		  this->surname.clear();
		  this->login.clear();
		  this->password.clear();
		  delete this->listOfproduct;
		  delete this->Basket;
	  }*/
	  void Print() {
		  cout << "\nName: " << this->name << " " <<"Surname: "<<this->surname << " " << "\nRang: " 
			  << this->rang << endl;
	  }
	  friend ostream& operator <<(ostream& stream, Employee& employee) {
		  employee.Print();
		  return stream;
	  }
	  bool Empty() { return (this->login == "" && this->name == "") ? true:false; }
	  void setName(string name) { this->name = name; }
	  void setSurname(string surname) { this->surname = surname; }
	  void setPassword(string password) { this->password = password; }
	  void setLogin(string login) { this->login = login; }
	  void setRang(string rang) { this->rang = rang; }
	  string getName() { return this->name; }
	  string getSurname() { this->surname = surname; }
	  string getPassword() { return this->password; }
	  string getRang() { return this->rang; }
	  uint32_t getDiscount() { return discount; }
	  void AddNewProd() {
		  char choise;
		  string name, stock;
		  double price; uint32_t id;
		  while (true) {
			  system("cls");
			  listOfproduct->PrintList();
			  cout << "\nEntering information for fdding product: " << endl;
			  cout << "\n-name of position: ";
			  cin >> name;
			  cout << "\n-price: ";
			  cin >> price;
			  cout << "\n-stock (stock/not): ";
			  cin >> stock;
			  cout << "\n-id:";
			  cin >> id;
			  listOfproduct->AddProduct(name, price, id, stock);
			  system("cls");
			  listOfproduct->PrintList();
			  cout << "\nDo you want continue: (y/n)";
			  cin >> choise;
			  if (choise == 'n') {
				  system("cls");
				  listOfproduct->PrintList();
				  system("pause");
			  }
		  }
	  }
	  void Test() {
		  listOfproduct->ReadyProd();
	  }
	  void ChangeInventary() {
		  listOfproduct->Inventory();
	  }
	  void DelProd() {
		  char choise;
		  uint32_t position;
		  while (true) {
			  system("cls");
			  cout << "\nList of product: " << endl;
			  cout << endl;
			  listOfproduct->PrintList();
			  cout << "\nChoise item for deleting: ";
			  cin >> position;
			  listOfproduct->DelProd(position);
			  cout << "\nDo you want continue: (y/n)";
			  cin >> choise;
			  if (choise == 'n') {
				  system("cls");
				  listOfproduct->PrintList();
				  system("pause");
			  }
		  }
	  }
	  void MakePurchase() {
		  char choise;
		  while (true) {
			  listOfproduct->ReadyProd();
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
				  system("pause");
				  break;
			  }
		  }
		  system("cls");
		  Basket->ShowList();
		  cout << "\n\t\t\tChek is: " << Basket->TotalSum(this->discount) << "  uah" << endl;
		  system("pause");
	  }
};

class Meneger:public Employee {
public:
	Meneger(string name, string surname, string login, string password) {
		this->setName(name);
		this->setSurname(surname);
		this->setRang("Meneger");
		this->setPassword(password);
		this->login = login;
		this->discount = 20;
	}
	/*~Meneger() {
		this->name.clear();
		this->password.clear();
		this->rang.clear();
		this->surname.clear();
		this->login.clear();
	}*/

};
class TopMeneger :public Employee {
public:
	TopMeneger(string name, string surname,string password,string login) {
		this->setName(name);
		this->setSurname(surname);
		this->setRang("Top");
		this->setPassword(password);
		this->login = login;
	}
};

class ListEmpl {
	private:
		map <string, Employee>* listEmpl;
		map <string, Meneger>* listMenger;
		map <string, TopMeneger>* listTop;
	public:
		ListEmpl() {
			listEmpl = new map < string, Employee>();
			listMenger = new map < string, Meneger>();
			listTop = new map <string, TopMeneger>();
		}
		~ListEmpl() {
			delete listEmpl;
			delete listMenger;
			delete listTop;
		}
		void AddEml(string name, string sekondName, string login, string password) {
			Employee empl(name, sekondName, login, password);
			pair<string, Employee> custom(login, empl);
			listEmpl->insert(custom);
		}
		void AddMeneger(string name, string sekondName, string login, string password) {
			Meneger empl(name, sekondName, login, password);
			pair<string, Meneger> custom(login, empl);
			listMenger->insert(custom);
		}
		void AddTop(string name, string sekondName, string login, string password) {
			TopMeneger empl(name, sekondName, login, password);
			pair<string, TopMeneger> custom(login, empl);
			listTop->insert(custom);
		}
		void AddNewEmpl() {
			bool a = true;
			char choise;
			string name, sekondName;
			string rang;
			string login, password;
			while (a) {
				system("cls");
				cout << "\nEntering information for adding account: " << endl;
				cout << "\n-name : ";
				cin >> name;
				cout << "\n-Sekond Name : ";
				cin >> sekondName;
				cout << "\n-login:";
				cin >> login;
				cout << "\n-rang(top/meneger/employee): ";
				cin >> rang;
				cout << "\n-password";
				cin >> password;
				auto item = this->listEmpl->find(login);
				auto itemMeneg = this->listMenger->find(login);
				auto itemTop = this->listTop->find(login);
				if (item== listEmpl->end() || itemMeneg==listMenger->end() || itemTop==listTop->end()) {
					if (rang == "meneger" || rang == "Meneger" || rang == "MENEGER") {
						AddMeneger(name, sekondName, login, password);
						a = false;
					}
					else if(rang=="Top"||rang=="top"||rang=="TOP") {
						AddTop(name, sekondName, login, password);
						a = false;
					}
					else {
						AddEml(name, sekondName, login, password);
						a = false;
					}
				}
				else {
					cout << "\nLogin alredy in use!" << endl;
					system("pause");
				}
			}
			system("pause");
		}
		Employee* FindEmpl() {
			system("cls");
			string login;
			string password;
			cout << "\n\t\tInput data for sign in:" << endl;
			cout << endl;
			cout << "\n\t\t>login: ";
			cin >> login;
			cout << "\n\t\t>password: ";
			cin >> password;
			auto item=listEmpl->find(login);
			if (item==listEmpl->end() || item->second.getPassword() != password) {
				cout << "\n\t\tUncorrect data!" << endl;
				cout << "\n\tDo you want continiue?(y/n)" << endl;
				char ch;
				cin >> ch;
				if (ch == 'n') {
					system("exit");
				}
			}
			else {
				return &item->second;
			}
		}
		Meneger* FindMeneg() {
			string login;
			string password;
			cout << "\n\t\tInput data for sign in:" << endl;
			cout << endl;
			cout << "\n\t\t>login: ";
			cin >> login;
			cout << "\n\t\t>password: ";
			cin >> password;
			auto item = listMenger->find(login);
			if (item==listMenger->end() || item->second.getPassword() != password) {
				cout << "\n\t\tUncorrect data!" << endl;
				system("pause");
				cout << "\n\tDo you want continiue?(y/n)" << endl;
				char ch;
				cin >> ch;
				if (ch == 'n') {
					system("exit");
				}
			}
			else {
				return &item->second;
			}
		}
		TopMeneger* FindTop() {
			string login;
			string password;
			cout << "\n\t\tInput data for sign in:" << endl;
			cout << endl;
			cout << "\n\t\t>login: ";
			cin >> login;
			cout << "\n\t\t>password: ";
			cin >> password;
			auto item = listTop->find(login);
			if (item==listTop->end() || item->second.getPassword() != password) {
				cout << "\n\t\tUncorrect data!" << endl;
				system("pause");
				cout << "\n\tDo you want continiue?(y/n)" << endl;
				char ch;
				cin >> ch;
				if (ch == 'n') {
					system("exit");
				}
			}
			else {
				return &item->second;
			}
		}

};