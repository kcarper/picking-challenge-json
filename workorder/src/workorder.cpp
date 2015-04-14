#include "workorder.h"

Order::Order() {
}

void Order::setBin(string const &bin) {
	bin_ = bin;
}

void Order::setItem(string const &item) {
	item_ = item;
}

const string& Order::getBin() const {
	return bin_;
}

const string& Order::getItem() const {
	return item_;
}

Json::Value Order::ToJson() const {
	Json::Value value(Json::objectValue);
	value["bin"] = bin_;
	value["item"] = item_;
	return value;
}

WorkOrder::WorkOrder() {
	orders_ = vector<Order>();
}

const vector<Order>& WorkOrder::getOrders() const {
	return orders_;
}

void WorkOrder::AddOrder(string const &bin, string const &item) {
	Order order = Order();
	order.setBin(bin);
	order.setItem(item);
	orders_.push_back(order);
}

void WorkOrder::JsonSave(const char* filename) {
	ofstream out(filename, ofstream::out);
	Json::Value workOrderJson(Json::objectValue), ordersJson(Json::arrayValue);
	for (vector<Order>::iterator it = orders_.begin(); it != orders_.end(); ++it) {
		ordersJson.append((*it).ToJson());
	}
	workOrderJson["work_order"] = ordersJson;
	out << workOrderJson;
	out.close();
}

void WorkOrder::JsonLoad(const char* filename) {
  ifstream in(filename);
  Json::Value workOrderJson;
  in >> workOrderJson;
  for (Json::Value::iterator it = workOrderJson["work_order"].begin(); it != workOrderJson["work_order"].end(); ++it) {
    AddOrder((*it)["bin"].asString(), (*it)["item"].asString());
  }
  in.close();
}