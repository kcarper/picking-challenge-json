#include <cstring>
#include <iostream>

#include "shelf.h"

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILENAME" << endl
         << "load the Amazon Picking Challenge bin contents from JSON file, FILENAME, and print out its contents." << endl;
    return 1;
  }
  Shelf shelf;
  shelf.JsonLoad(argv[1]);
  for (vector<Bin>::const_iterator it = shelf.getBins().begin(); it != shelf.getBins().end(); ++it) {
    cout << (*it).getName() << endl;
    for (vector<string>::const_iterator it2 = (*it).getItems().begin(); it2 != (*it).getItems().end(); ++it2) {
      cout << '\t' + (*it2) << endl;
    }
  }
  return 0;
}