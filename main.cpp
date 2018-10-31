#include "relation.h"
//#include "header.h"
#include "row.h"
#include "cvpair.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

  //I don't understand why I need to RENAME things before I query them
  //But my rename function works.

  vector<string> columns = {"A", "B", "C"};
  Relation myRelation("My Table", columns);
//Test 1: print empty table
  cout << "Test 1: print empty table" << endl;
  cout << myRelation.toString();
//Test 2: add rows
  vector<string> row1 = {"alpha", "alpha", "alpha"};
  vector<string> row2 = {"apple", "banana", "grape"};
  vector<string> row3 = {"ant", "bee", "giraffe"};
  myRelation.insertRow(row1);
  myRelation.insertRow(row2);
  myRelation.insertRow(row3);
  cout << "Test 2: add rows" << endl;
  cout << myRelation.toString();
//Test 3: rename a column
  CVPair colValPair = CVPair(2, "G");
  vector<CVPair> cvpList = {colValPair};
  Relation myRelation1 = myRelation.rename(cvpList);
  cout << "Test 3: rename column" << endl;
  cout << myRelation1.toString();
//Test 4: Q('apple', 'banana')?
  CVPair colValPair1(0, "apple");
  CVPair colValPair2(1, "banana");
  cvpList = {colValPair1, colValPair2};
  vector<int> columnsToKeep = {0, 1};
  Relation myRelation2 = myRelation1.select(cvpList);
  myRelation2 = myRelation2.project(columnsToKeep);
  cout << "Test 4: Q('apple', 'banana')?" << endl;
  cout << myRelation2.toString();
//Test 5: Q(X, X, X)?
  CCPair colColPair1(0, 1);
  CCPair colColPair2(0, 2);
  vector<CCPair> ccpList = {colColPair1, colColPair2};
  columnsToKeep = {0, 1, 2};
  myRelation2 = myRelation1.select(ccpList);
  myRelation2 = myRelation2.project(columnsToKeep);
  cout << "Test 5: Q(X, X, X)?" << endl;
  cout << myRelation2.toString();
//Test 6: Q(X, Y, 'giraffe')?
  colValPair = CVPair(2, "giraffe");
  cvpList = {colValPair};
  columnsToKeep = {0, 1};
  myRelation2 = myRelation1.select(cvpList);
  myRelation2 = myRelation2.project(columnsToKeep);
  cout << "Test 6: Q(X, Y, 'giraffe')?" << endl;
  cout << myRelation2.toString();

//new Relation example
  columns = {"student", "teacher", "grade"};
  myRelation = Relation("school", columns);
  row1 = {"Jim", "Robinson", "B+"};
  row2 = {"Anne", "Robinson", "A"};
  row3 = {"Bill", "Smith", "A-"};
  vector<string> row4 = {"Chayne", "Smith", "C+"};
  vector<string> row5 = {"Emily", "Fellows", "A"};
  vector<string> row6 = {"George", "Robinson", "B+"};
  vector<string> row7 = {"Anne", "Smith", "A"};
  vector<string> row8 = {"Emily", "Robinson", "A"};
  myRelation.insertRow(row1);
  myRelation.insertRow(row2);
  myRelation.insertRow(row3);
  myRelation.insertRow(row4);
  myRelation.insertRow(row5);
  myRelation.insertRow(row6);
  myRelation.insertRow(row7);
  myRelation.insertRow(row8);
//Print original Relation
  cout << "New Relation Example:" << endl;
  cout << myRelation.toString();
//Test 7: Q(X, 'Smith', Y)?
  colValPair = CVPair(0, "X");
  colValPair1 = CVPair(2, "Y");
  cvpList = {colValPair, colValPair1};
  myRelation1 = myRelation.rename(cvpList);
  colValPair2 = CVPair(1, "Smith");
  cvpList = {colValPair2};
  myRelation1 = myRelation1.select(cvpList);
  columnsToKeep = {0, 2};
  myRelation1 = myRelation1.project(columnsToKeep);
  cout << "Test 7: Q(X, 'Smith', Y)?" << endl;
  cout << myRelation1.toString();
//Test 8: Q('Emily', Y, 'A')?
  colValPair = CVPair(0, "X");
  colValPair1 = CVPair(1, "Y");
  colValPair2 = CVPair(2, "X");
  cvpList = {colValPair, colValPair1, colValPair2};
  myRelation1 = myRelation.rename(cvpList);
  CCPair colColPair(0, 2);
  ccpList = {colColPair};
  myRelation1 = myRelation1.select(ccpList);
  columnsToKeep = {0, 1, 2};
  myRelation1 = myRelation1.project(columnsToKeep);
  cout << "Test 8: Q(X, Y, X)?" << endl;
  cout << myRelation1.toString();
//Test 9:
//Test 10:
  return 0;
}
