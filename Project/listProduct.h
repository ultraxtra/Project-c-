#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;

class product {
	string  positionName;
	double price;
	uint32_t id;
	string isAvailable;
public:
	product(string  positionName, double price, uint32_t id, string isAvailable) {
		this->positionName = positionName;
		this->price = price;
		this->id = id;
		this->isAvailable = isAvailable;
		
	}
	bool isEmpty() {
		return((this->positionName == ""&& this->id==0&&this->isAvailable==""&&this->price==0) ? true : false);
	}
	product() :product("",0, 0,"") {};
	~product() {
		this->positionName.clear();
	}
	product* operator=(product* obj) {
		this->id = obj->id;
		this->isAvailable = obj->isAvailable;
		this->positionName = obj->positionName;
		this->price = obj->price;
		return this;
	}
	void setPrice(uint32_t price) { this->price = price; }
	void setPositionName(string  positionName) { this->positionName = positionName; }
	void setAvailadl(string availbale) { this->isAvailable = availbale; }
	string getAvailbl() { return this->isAvailable; }
	string getPositionName() { return this->positionName; }
	double getPrice() { return this->price; }
	uint32_t getID() { return this->id; }
	friend ostream& operator <<(ostream& stream, product& prod) {
		stream << prod.id << " " << prod.positionName << " " << prod.price << " " << prod.isAvailable 
			<< endl;
		return stream;
	}
	
};
class listProduct
{
	map <uint32_t, product>* listProd;
public:
	listProduct() {
		listProd = new map <uint32_t, product>();
	}
	/*~listProduct() {
		delete listProd;
	}*/
	void AddProduct(string  positionName, double price, uint32_t id, string available) {
		product Product(positionName, price, id, available);
		pair<uint32_t, product> prod(id, Product);
		listProd->insert(prod);
	}

	void ReadyProd() {
		const int N = 5;
		product p1("Sumsung p150  ",  15000, 1, "not");
		product p2("Redmi  ",  12000, 2, "not");
		product p3("Apple  ", 100000, 3, "not");
		product p4("Macbook  ", 40000, 4, "stock");
		product p5("HP  ", 1000, 5, "stock");
		pair<uint32_t, product> prod[N] = {
			{1,p1},
			{2,p2},
			{3,p3},
			{4,p4},
			{5,p5},
		};
		for (size_t i = 0; i < N; i++) {
			listProd->insert(prod[i]);
		}
	}
	listProduct* operator = (listProduct* obj2) {
		if (!this->listProd->empty()) {
			this->listProd->clear();
		}
		auto item = obj2->listProd->begin();
		auto item2 = this->listProd->begin();
		for (; item != obj2->listProd->end(); item++,item2++) {
			item2.operator=(item);
		}
	}
	product& getProduct(uint32_t id) {
		auto item = this->listProd->find(id);
		product& tmp = item->second;
		if (!tmp.isEmpty()) {
			return tmp;
		}
		else
		{
			return tmp;
		}
	}
	void setlistProd(map <uint32_t, product>* listProd) { this->listProd = listProd; }
	void DelProd(uint32_t id) {
		map <uint32_t, product>::iterator it;
		it = listProd->find(id);
		if (!(it->second.isEmpty())){
			listProd->erase(id);
		}
		else {
			cout << "\nValue is not found!" << endl;
		}
	}
	void PrintList() {
		auto item = listProd->begin();
		if (!listProd->empty()) {
			for (; item != listProd->end(); item++) {
				cout<< item->second << endl;
			}
		}
		else {
			cout << "\nList is empty" << endl;
		}
	}
	void ChangeStock(uint32_t id,string stock) {
		auto item = listProd->find(id);
		item->second.getAvailbl().clear();
		item->second.setAvailadl(stock);
	}
	void Inventory()
	{
		uint32_t valueStock;
		string stock;
		char y;
		map <uint32_t, product>::iterator it;
		while (true) {
			system("cls");
			it = listProd->begin();
			for (; it != listProd->end(); it++) {
				if (it->second.getAvailbl() == "not") {
					cout << it->second << endl;
				}
			}
			cout << "\n Input id for changes value of the stock: ";
			cin >> valueStock;
			cout << "\n Input the value of the stock: ";
			cin >> stock;
			this->ChangeStock(valueStock, stock);
			cout << "\nDo you want to continue? (y/n): ";
			cin >> y;
			if (y == 'n') {
				return;
			}
		}
	}
};

