#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "json/json.h"

using namespace std;

class Bin {
private:
	string name_;
	vector<string> items_;
public:
	Bin();
	void setName(string const &name);
	void setItems(vector<string> const &items);
	const string& getName() const;
	const vector<string>& getItems() const;
};

class Shelf {
private:
	vector<Bin> bins_;
public:
	Shelf();
	const vector<Bin>& getBins() const;
	void JsonLoad(const char* filename);

	void addBin(string const &name, vector<string> const &items);
	const vector<Bin>::iterator& begin();
	const vector<Bin>::iterator& end();
};
