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
  vector<string> row2 = {"apple", "banana", "grape"};
  vector<string> row3 = {"ant", "bee", "giraffe"};
  myRelation.insertRow(row1);
  myRelation.insertRow(row2);
  myRelation.insertRow(row3);
  cout << myRelation.toString();
/*
  CVPair colValPair(1, "D");
  Relation myRelation2 = myRelation;
  myRelation2.rename(colValPair);
  cout << myRelation2.toString();
  */
  CVPair colValPair1(0, "ant");
  CVPair colValPair2(1, "bee");
  vector<CVPair> cvpList = {colValPair1, colValPair2};
  Relation myRelation3 = myRelation;
  myRelation3.select(cvpList);
  cout << myRelation3.toString();
  return 0;
}
