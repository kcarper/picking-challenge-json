#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "json/json.h"

using namespace std;

class Order {
private:
	string bin_;
	string item_;
public:
	Order();
	void setBin(string const &bin);
	void setItem(string const &item);
	const string& getBin() const;
	const string& getItem() const;
	Json::Value ToJson() const;
};

class WorkOrder {
private:
	vector<Order> orders_;
public:
	WorkOrder();
	const vector<Order>& getOrders() const;
	void JsonSave(const char* filename);
	void JsonLoad(const char* filename);

	void AddOrder(string const &bin, string const &item);
	const vector<Order>::iterator& begin();
	const vector<Order>::iterator& end();
};