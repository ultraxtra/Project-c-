#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "basket.h"
#include "customer.h"
#include "Employee.h"
#include"listProduct.h"
#include "Interf.h"
using namespace std;

class system_meneg {
public:
	listCustomers* customers;
	listProduct* listProd;
	ListEmpl* empl;
		system_meneg() {
			customers = new listCustomers();
			listProd = new listProduct();
			empl = new ListEmpl();
		}
		~system_meneg() {
			delete customers;
			delete listProd;
			delete empl;
		}
		void CreateAccount() {
			char choise='0';
			cout << "\n\t\t\tPlease, select an account type" << endl;
			cout << "\n\t\t\t1>Costumer" << endl;
			cout << "\n\t\t\t2>Employee" << endl;
			cout << "\n\t\t\t3>Exit" << endl;
			cin >> choise;
			if (choise == '1') {
				customers->AddNewCustomer();
				SignINCustom();
				system("pause");
				StartInterfaceMenu();
				
			}
			else if (choise == '2') {
				empl->AddNewEmpl();
				SignInEmpl();
				system("pause");
				StartInterfaceMenu();
			}
			else if (choise == '3') {
				StartInterfaceMenu();
				return;
			}
			else {
				cout << "\n\tUncorrect value!" << endl;
				system("pause");
				system("cls");
				CreateAccount();
				system("pause");
				StartInterfaceMenu();
			}
		}
		char Menu() {
			system("cls");
			char choise;
			cout << "\n\t\tMenu" << endl;
			cout << endl;
			cout << "\n\t\t1-Print all bayer" << endl;
			cout << "\n\t\t2-Print VIP" << endl;
			cout << "\n\t\t3-Print active bayer " << endl;
			cout << "\n\t\t4-Add new product" << endl;
			cout << "\n\t\t5-Remove product" << endl;
			cout << "\n\t\t6-Inventory" << endl;
			cout << "\n\t\t7-Make a purshe" << endl;
			cout << "\n\t\t8-Exit" << endl;
			cin >> choise;
			return choise;
		}
		void SignInEmpl() {
			system("cls");
			char choise;
			cout << "\n\t\t1-Employee" << endl;
			cout << "\n\t\t2-Meneger" << endl;
			cout << "\n\t\t3-Top" << endl;
			cout << "\n\t\t4-Return" << endl;
			cout << "\n\t\tAnswer: " << endl;
			cin >> choise;
			if (choise == '1') {
				while (true) {
					system("cls");
					char ch;
					auto item = empl->FindEmpl();
					cout << "\n\t\tHello!";
					item->Print();
					ch = Menu();
					if (ch == '1') {
						system("cls");
						customers->PrintAll();
						system("pause");
						continue;
					}
					else if (ch == '2') {
						system("cls");
						customers->PrintVIP();
						system("pause");
						continue;
					}
					else if (ch == '3') {
						system("cls");
						customers->PrintActive();
						system("pause");
						continue;
					}
					else if (ch =='4') {
						system("cls");
						string position;
						double price;
						string stock;
						uint32_t id;
						cout << "\n\t Entering: " << endl;
						cout << "\n\t-name position: " << endl;
						cin >> position;
						cout << "\n\t-price: " << endl;
						cin >> price;
						cout << "\n\t-stock(stock\not):";
						cin >> stock;
						cout<<"\n\t-id:";
						cin >> id;
						system("cls");
						listProd->AddProduct(position,price,id,stock);
						system("cls");
						listProd->PrintList();
						system("pause");
						continue;
					}
					else if (ch == '5') {
						while (true) {
							char c;
							uint32_t id;
							system("cls");
							listProd->PrintList();
							cout << "\n\t\tEnter id for deleting" << endl;
							cin >> id;
							listProd->DelProd(id);
							listProd->PrintList();
							system("pause");
							cout << "\n\t\tDo you whant to continue(y/n)?  ";
							cin >> c;
							if (c == 'n') {
								break;
							}
						}
					}
					else if (ch == '6') {
						system("cls");
						listProd->Inventory();
					}
					else if (ch== '7') {
						system("cls");
						item->MakePurchase();
					}
					else if (ch== '8') {
						system("cls");
						StartInterfaceMenu();
					}
				}
			}
			else if (choise == '2') {
				system("cls");
				auto item = empl->FindMeneg();
				item->Print();
				while (true) {
					system("cls");
					char chois;
					auto item = empl->FindMeneg();
					cout << "\n\t\tHello!";
					item->Print();
					chois = Menu();
					if (chois == '1') {
						system("cls");
						customers->PrintAll();
						system("pause");
						continue;
					}
					else if (chois == '2') {
						system("cls");
						customers->PrintVIP();
						system("pause");
						continue;
					}
					else if (chois == '3') {
						system("cls");
						customers->PrintActive();
						system("pause");
						continue;
					}
					else if (chois == '4') {
						system("cls");
						string position;
						double price;
						string stock;
						uint32_t id;
						system("cls");
						cout << "\n\t Entering: " << endl;
						cout << "\n\t-name position: " << endl;
						cin >> position;
						cout << "\n\t-price: " << endl;
						cin >> price;
						cout << "\n\t-stock(stock\not):";
						cin >> stock;
						cout << "\n\t-id:";
						cin >> id;
						listProd->AddProduct(position, price, id, stock);
						system("cls");
						listProd->PrintList();
						system("pause");
						continue;
					}
					else if (chois == '5') {
						while (true) {
							char c;
							uint32_t id;
							system("cls");
							listProd->PrintList();
							cout << "\n\t\tEnter id for deleting" << endl;
							cin >> id;
							listProd->DelProd(id);
							listProd->PrintList();
							system("pause");
							cout << "\n\t\tDo you whant to continue(y/n)?  ";
							cin >> c;
							if (c == 'n') {
								break;
							}
						}
					}
					else if (chois == '6') {
						system("cls");
						listProd->Inventory();
						
					}
					else if (chois == '7') {
						system("cls");
						item->MakePurchase();
					}
					else if (chois == '8') {
						StartInterfaceMenu();
					}
				}
			}
			else if(choise=='3') {
				while (true) {
					system("cls");
					char chs;
					auto item = empl->FindTop();
					cout << "\n\t\tHello!";
					item->Print();
					chs = Menu();
					if (chs == '1') {
						customers->TestCustomer();
						system("cls");
						customers->PrintAll();
						system("pause");
						continue;
					}
					else if (chs == '2') {
						system("cls");
						customers->PrintVIP();
						system("pause");
						continue;
					}
					else if (chs == '3') {
						system("cls");
						customers->PrintActive();
						system("pause");
						continue;
					}
					else if (chs == '4') {
						system("cls");
						string position;
						double price;
						string stock;
						uint32_t id;
						system("cls");
						cout << "\n\t Entering: " << endl;
						cout << "\n\t-name position: " << endl;
						cin >> position;
						cout << "\n\t-price: " << endl;
						cin >> price;
						cout << "\n\t-stock(stock\not):";
						cin >> stock;
						cout << "\n\t-id:";
						cin >> id;
						listProd->AddProduct(position, price, id, stock);
						system("cls");
						listProd->PrintList();
						system("pause");
						continue;
					}
					else if (chs == '5') {
						while (true) {
							char c;
							uint32_t id;
							system("cls");
							listProd->PrintList();
							cout << "\n\t\tEnter id for deleting" << endl;
							cin >> id;
							listProd->DelProd(id);
							listProd->PrintList();
							system("pause");
							cout << "\n\t\tDo you whant to continue(y/n)?  ";
							cin >> c;
							if (c == 'n') {
								system("cls");
								StartInterfaceMenu();
							}
						}
					}
					else if (chs == '6') {
						system("cls");
						listProd->Inventory();
					}
					else if (chs== '7') {
						system("cls");
						item->MakePurchase();
					}
					else if (chs == '8') {
						system("cls");
						StartInterfaceMenu();
					}
				}
			}
			else if (choise == '3') {
			
			}
			else {
			  system("cls");
			  cout << "\n\t\tUncorrect Value!" << endl;
			  system("pause");
			}
		}
		void SignINCustom() {
			system("cls");
			char choise;
			cout << "\n\t\tYou are VIP(y/n)?" << endl;
			cout << endl;
			cin >> choise;
			if (choise == 'y') {
				auto item=customers->FindVip();
				cout << "\n\t\tHello! " << item->getname() << endl;
				system("pause");
				listProd->ReadyProd();
				listProd->PrintList();
				item->MakePurchase();
			}
			else if (choise == 'n') {
				system("cls");
				auto item = customers->FindCustom();
				cout << "\n\t\tHello! " << item->getname() << endl;
				system("pause");
				listProd->ReadyProd();
				listProd->PrintList();
				item->MakePurchase();
			}
		}
};