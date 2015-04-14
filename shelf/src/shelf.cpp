#include "shelf.h"

Bin::Bin() {
}

void Bin::setName(string const &name) {
	name_ = name;
}

void Bin::setItems(vector<string> const &items) {
	items_ = items;
}

const string& Bin::getName() const {
	return name_;
}

const vector<string>& Bin::getItems() const {
	return items_;
}

Shelf::Shelf() {
	bins_ = vector<Bin>();
}

const vector<Bin>& Shelf::getBins() const {
	return bins_;
}

void Shelf::addBin(string const &name, vector<string> const &items) {
	Bin bin = Bin();
	bin.setName(name);
	bin.setItems(items);
	bins_.push_back(bin);
}

void Shelf::JsonLoad(const char* filename) {
	ifstream in(filename);
	Json::Value shelf;
	in >> shelf;
	string base = "bin_";
	string name;
	vector<string> items;
    for (int i = 0; i < 12; ++i) {
		items = vector<string>();
		name = base+(char)('A'+i);
		for (int j = 0; j < shelf["bin_contents"][name].size(); ++j) {
			items.push_back(shelf["bin_contents"][name][j].asString());	
		}
	addBin(name, items);
	}
	in.close();
}
	







