#include <cstring>
#include <iostream>

#include "workorder.h"

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILENAME" << endl
         << "load the Amazon Picking Challenge work order from JSON file, FILENAME, and print out its contents." << endl;
    return 1;
  }
  WorkOrder work_order;
  work_order.JsonLoad(argv[1]);
  for (vector<Order>::const_iterator it = work_order.getOrders().begin(); it != work_order.getOrders().end(); ++it) {
    cout << (*it).getBin() << "," << (*it).getItem() << endl;
  }
  return 0;
}