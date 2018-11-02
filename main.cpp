#include "relation.h"
//#include "header.h"
#include "row.h"
#include "cvpair.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string compare(Relation myRelation, Relation testRelation) {
  if (myRelation.toString() == testRelation.toString()) {
    return "Success!";
  }
  return "Fail";
}

int main() {

  CVPair cvp1;
  CVPair cvp2;
  CVPair cvp3;
  CCPair ccp1;
  CCPair ccp2;
  vector<string> columns;
  vector<string> testColumns;
  vector<string> row;
  vector<string> testRow;
  vector<CVPair> cvpList;
  vector<CCPair> ccpList;
  vector<int> columnsToKeep;
  Relation myRelation;
  Relation myRelationEdit1;
  Relation myRelationEdit2;
  Relation testRelation;

//New Relation
  columns = {"A", "B", "C"};
  myRelation = Relation("My Table", columns);
  row = {"alpha", "alpha", "alpha"};
  myRelation.insertRow(row);
  row = {"apple", "banana", "grape"};
  myRelation.insertRow(row);
  row = {"ant", "bee", "giraffe"};
  myRelation.insertRow(row);

//Test 1: Select using Column Value Pairs
  cvp1 = CVPair(0, "ant");
  cvpList = {cvp1};
  myRelationEdit1 = myRelation.select(cvpList);
//  cout << myRelation1.toString();

//Comparison Relation
  testColumns = {"A", "B", "C"};
  testRelation = Relation("My Table", testColumns);
  testRow = {"ant", "bee", "giraffe"};
  testRelation.insertRow(testRow);
//  cout << testRelation.toString();

  cout << "Test 1: " << compare(myRelationEdit1, testRelation) << endl;

//Test 2: project two columns
  columnsToKeep = {0, 2};
  myRelationEdit1 = myRelation.project(columnsToKeep);

//Comparison Relation
  testColumns = {"A", "C"};
  testRelation = Relation("My Table", testColumns);
  testRow = {"alpha", "alpha"};
  testRelation.insertRow(testRow);
  testRow = {"apple", "grape"};
  testRelation.insertRow(testRow);
  testRow = {"ant", "giraffe"};
  testRelation.insertRow(testRow);

  cout << "Test 2: " << compare(myRelationEdit1, testRelation) << endl;

//Test 3: rename a column
  cvp1 = CVPair(2, "G");
  cvpList = {cvp1};
  myRelationEdit1 = myRelation.rename(cvpList);
//  cout << myRelationEdit1.toString();

//Comparison Relation
  testColumns = {"A", "B", "G"};
  testRelation = Relation("My Table", testColumns);
  row = {"alpha", "alpha", "alpha"};
  testRelation.insertRow(row);
  row = {"ant", "bee", "giraffe"};
  testRelation.insertRow(row);
  row = {"apple", "banana", "grape"};
  testRelation.insertRow(row);
//  cout << testRelation.toString();

  cout << "Test 3: " << compare(myRelationEdit1, testRelation) << endl;

//Test 4: Q('apple', 'banana')?
  cvp1 = CVPair(0, "apple");
  cvp2 = CVPair(1, "banana");
  cvpList = {cvp1, cvp2};
  columnsToKeep = {0, 1};
  myRelationEdit2 = myRelationEdit1.select(cvpList);
  myRelationEdit2 = myRelationEdit2.project(columnsToKeep);
//  cout << "Test 4: Q('apple', 'banana')?" << endl;
//  cout << myRelationEdit2.toString();

//Comparison Relation
  testColumns = {"A", "B"};
  testRelation = Relation("My Table", testColumns);
  testRow = {"apple", "banana"};
  testRelation.insertRow(testRow);

  cout << "Test 4: " << compare(myRelationEdit2, testRelation) << endl;

//Test 5: Q(X, X, X)?

//RENAME RENAME RENAME
  ccp1 = CCPair(0, 1);
  ccp2 = CCPair(0, 2);
  ccpList = {ccp1, ccp2};
  columnsToKeep = {0, 1, 2};
  myRelationEdit2 = myRelationEdit1.select(cvpList);
  myRelationEdit2 = myRelationEdit2.project(columnsToKeep);
  cvp1 = CVPair(0, "X");
  cvp2 = CVPair(1, "X");
  cvp3 = CVPair(2, "X");
  cvpList = {cvp1, cvp2, cvp3};
  myRelationEdit2 = myRelationEdit2.rename(cvpList);
//  cout << "Test 5: Q(X, X, X)?" << endl;
//  cout << myRelationEdit2.toString();

//Comparison Relation
  testColumns = {"X", "X", "X"};
  testRelation = Relation("My Table", testColumns);
  testRow = {"apple", "banana", "grape"};
  testRelation.insertRow(testRow);

  cout << "Test 5: " << compare(myRelationEdit2, testRelation) << endl;

//Test 6: Q(X, Y, 'giraffe')?
//RENAME RENAME RENAME
  cvp1 = CVPair(2, "giraffe");
  cvpList = {cvp1};
  myRelationEdit2 = myRelationEdit1.select(cvpList);
  columnsToKeep = {0, 1};
  myRelationEdit2 = myRelationEdit2.project(columnsToKeep);
  cvp1 = CVPair(0, "X");
  cvp2 = CVPair(1, "Y");
  cvpList = {cvp1, cvp2};
  myRelationEdit2 = myRelationEdit2.rename(cvpList);
//  cout << myRelationEdit2.toString();

//Comparison Relation
  testColumns = {"X", "Y"};
  testRelation = Relation("My Table", testColumns);
  testRow = {"ant", "bee"};
  testRelation.insertRow(testRow);
//  cout << testRelation.toString();

  cout << "Test 6: " << compare(myRelationEdit2, testRelation) << endl;

//new Relation example
  columns = {"student", "teacher", "grade"};
  myRelation = Relation("school", columns);
  row = {"Jim", "Robinson", "B+"};
  myRelation.insertRow(row);
  row = {"Anne", "Robinson", "A"};
  myRelation.insertRow(row);
  row = {"Bill", "Smith", "A-"};
  myRelation.insertRow(row);
  row = {"Chayne", "Smith", "C+"};
  myRelation.insertRow(row);
  row = {"Emily", "Fellows", "A"};
  myRelation.insertRow(row);
  row = {"George", "Robinson", "B+"};
  myRelation.insertRow(row);
  row = {"Anne", "Smith", "A"};
  myRelation.insertRow(row);
  row = {"Emily", "Robinson", "A"};
  myRelation.insertRow(row);
//Print original Relation
//  cout << endl << "New Relation Example:" << endl;
//  cout << myRelation.toString();

//Test 7: Q(X, 'Smith', Y)?
  cvp1 = CVPair(1, "Smith");
  cvpList = {cvp1};
  myRelationEdit1 = myRelation.select(cvpList);
//  cout << myRelationEdit1.toString();
  columnsToKeep = {0, 2};
  myRelationEdit1 = myRelationEdit1.project(columnsToKeep);
  cvp1 = CVPair(0, "X");
  cvp2 = CVPair(1, "Y");
  cvpList = {cvp1, cvp2};
  myRelationEdit1 = myRelationEdit1.rename(cvpList);
//  cout << "Test 7: Q(X, 'Smith', Y)?" << endl;
//  cout << myRelationEdit1.toString();

//Comparison Relation
  testColumns = {"X", "Y"};
  testRelation = Relation("school", testColumns);
  row = {"Bill", "A-"};
  testRelation.insertRow(row);
  row = {"Chayne", "C+"};
  testRelation.insertRow(row);
  row = {"Anne", "A"};
  testRelation.insertRow(row);
//  cout << testRelation.toString();

  cout << "Test 7: " << compare(myRelationEdit1, testRelation) << endl;

//Test 8: Q('Emily', Y, 'A')?
  cvp1 = CVPair(0, "Emily");
  cvp2 = CVPair(2, "A");
  cvpList = {cvp1, cvp2};
  myRelationEdit1 = myRelation.select(cvpList);
//  cout << myRelationEdit1.toString();
  columnsToKeep = {1};
  myRelationEdit1 = myRelationEdit1.project(columnsToKeep);
  cvp1 = CVPair(0, "Y");
  cvpList = {cvp1};
  myRelationEdit1 = myRelationEdit1.rename(cvpList);
//  cout << "Test 8: Q(X, Y, X)?" << endl;
//  cout << myRelationEdit1.toString();

//Comparison Relation
  testColumns = {"Y"};
  testRelation = Relation("school", testColumns);
  row = {"Fellows"};
  testRelation.insertRow(row);
  row = {"Robinson"};
  testRelation.insertRow(row);
//  cout << testRelation.toString();

  cout << "Test 8: " << compare(myRelationEdit1, testRelation) << endl;

//New relation example
  columns = {"Due", "Scheduled", "Completed"};
  myRelation = Relation("To Do", columns);
  row = {"10/04", "10/03", "10/04"};
  myRelation.insertRow(row);
  row = {"10/10", "10/08", "10/08"};
  myRelation.insertRow(row);
  row = {"10/12", "10/12", "10/13"};
  myRelation.insertRow(row);
  row = {"10/15", "10/13", "10/15"};
  myRelation.insertRow(row);
  row = {"10/20", "10/20", "10/20"};
  myRelation.insertRow(row);
//Print Original Relation
//  cout << endl << "New Relation Example:" << endl;
//  cout << myRelation.toString();

//Test 9: select using Colomn Column Pairs
  ccp1 = CCPair(0, 1);
  ccp2 = CCPair(0, 2);
  ccpList = {ccp1, ccp2};
  myRelationEdit1 = myRelation.select(ccpList);
//  cout << "Test 9: Select using Column Column Pairs" << endl;
//  cout << myRelationEdit1.toString();

//Compare Relation
  testColumns = {"Due", "Scheduled", "Completed"};
  testRelation = Relation("To Do", testColumns);
  row = {"10/20", "10/20", "10/20"};
  testRelation.insertRow(row);

  cout << "Test 9: " << compare(myRelationEdit1, testRelation) << endl;

//Test 10: Q(X, '10/03', X)?
  cvp1 = CVPair(1, "10/03");
  cvpList = {cvp1};
  ccp1 = CCPair(0, 2);
  ccpList = {ccp1};
  myRelationEdit1 = myRelation.select(ccpList);
  myRelationEdit1 = myRelationEdit1.select(cvpList);
  columnsToKeep = {0, 2};
  myRelationEdit1 = myRelationEdit1.project(columnsToKeep);
  cvp1 = CVPair(0, "X");
  cvp2 = CVPair(1, "X");
  cvpList = {cvp1, cvp2};
  myRelationEdit1 = myRelationEdit1.rename(cvpList);
//  cout << "Test 10: Q(X, '10/03', X)?" << endl;
//  cout << myRelationEdit1.toString();

//Compare Relation
  testColumns = {"X", "X"};
  testRelation = Relation("To Do", testColumns);
  row = {"10/04", "10/04"};
  testRelation.insertRow(row);

  cout << "Test 10: " << compare(myRelationEdit1, testRelation) << endl;
  return 0;
}
