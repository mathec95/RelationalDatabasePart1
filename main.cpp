#include "relation.h"
//#include "header.h"
#include "row.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<string> columns = {"A", "B", "C"}; //don't remember how to initialize a vector
  myRelation = new Relation("My Table", columns);
  vector<string> row1 = {"alpha", "beta", "gamma"};
  myRelation.insertRow(row1);
  cout << myRelation.toString();
  return 0;
}
