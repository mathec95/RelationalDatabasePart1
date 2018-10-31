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
  vector<string> row1 = {"alpha", "alpha", "alpha"};
  vector<string> row2 = {"apple", "banana", "grape"};
  vector<string> row3 = {"ant", "bee", "giraffe"};
  myRelation.insertRow(row1);
  myRelation.insertRow(row2);
  myRelation.insertRow(row3);
//Print the original relation
  cout << myRelation.toString();
//Q("apple", "banana")?
  CVPair colValPair1(0, "apple");
  CVPair colValPair2(1, "banana");
  vector<CVPair> cvpList = {colValPair1, colValPair2};
  vector<int> columnsToKeep = {0, 1};
  Relation myRelation1 = myRelation.select(cvpList);
  myRelation1 = myRelation1.project(columnsToKeep);
  cout << myRelation1.toString();
//Q(X, X, X)?
  CCPair colColPair1(0, 1);
  CCPair colColPair2(0, 2);
  vector<CCPair> ccpList = {colColPair1, colColPair2};
  columnsToKeep = {0, 1, 2};
  Relation myRelation2 = myRelation.select(ccpList);
  myRelation2 = myRelation2.project(columnsToKeep);
  cout << myRelation2.toString();
//Q(X, Y, "giraffe")?
  CVPair colValPair(2, "giraffe");
  cvpList = {colValPair};
  columnsToKeep = {0, 1};
  Relation myRelation3 = myRelation.select(cvpList);
  myRelation3 = myRelation3.project(columnsToKeep);
  cout << myRelation3.toString();
  return 0;
}
