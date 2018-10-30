#include "relation.h"
//#include "header.h"
#include "row.h"
#include "cvpair.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<string> columns = {"A", "B", "C"}; //don't remember how to initialize a vector
  Relation myRelation("My Table", columns);
  vector<string> row1 = {"alpha", "beta", "gamma"};
  myRelation.insertRow(row1);
  cout << myRelation.toString();
  CVPair colValPair(1, "D");
  Relation myRelation2 = myRelation;
  myRelation2.rename(colValPair);
  cout << myRelation2.toString();
  return 0;
}
