
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "listProduct.h"
#include <iostream>
#include <vector>
#include <memory>
#include <time.h>
#include <sstream>

using namespace std;
class basket
{
	uint32_t sumPrice;
	vector <product>* listBasket;
	string data;
    public:
		basket() {
			sumPrice = 0;
			listBasket = new vector <product>();
			time_t t = time(nullptr);
			struct tm* now = localtime(&t);
			stringstream s;
			now->tm_year = 2022;
			now->tm_mon = 06;
			now->tm_wday = 03;
			s << (now->tm_wday) << ":" << (now->tm_mon) << ":" << (now->tm_year )<< endl;
			this->data = s.str();
		}
		~basket() {
			delete listBasket;
	    }
		void AddProduct(product&product) {
			listBasket->push_back(product);
		}
		string getData() { return this->data; }
		void DelProduct(uint32_t id) {
			vector <product>::iterator it;
			it = listBasket->begin();
			if (!it->isEmpty()) {
				for (; it != listBasket->end(); it++) {
					if (it->getID() == id) {
						listBasket->erase(it);
					}
				}
			}
			else {
				cout << "\nList is empty!" << endl;
			}
		}
		void ShowList() {
			cout << "\n\t\t\tChek: " << endl;
			cout << endl;
			vector <product>::iterator it;
			it = listBasket->begin();
			for (; it != listBasket->end(); it++) {
				cout <<"\t\t\t"<< * it << endl;
			}
			cout << getData() << endl;
		}
		uint32_t TotalSum(uint32_t discount) {
			vector <product>::iterator it;
			it = listBasket->begin();
			for (; it != listBasket->end(); it++) {
				this->sumPrice += it->getPrice();
			}
			return (this->sumPrice*(1-(discount/100)));
		}

};

