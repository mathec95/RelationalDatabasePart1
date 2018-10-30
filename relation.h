/*
data members:
string name (name of table)
Header object (a vector of the column names)
Rows (set of Row objects)
insert function (adds a row to the Row set)
*/

#ifndef RELATION_H
#define RELATION_H
#include "header.h"
#include "row.h"
#include "ccpair.h"
#include "cvpair.h"
#include <string>
#include <set>
#include <vector>

using namespace std;

class Relation {
private:
  string tableName;
  Header columnNames;
  set<Row> rows;
public:
  Relation(string newName, vector<string> newColumns);
  ~Relation()=default;
  void insertRow(const vector<string> newRow);
  void select(const vector<CVPair> cpvList);
  void select(const vector<CCPair> ccpList);
  //project function that takes vector of columns to keep
    // creates a new table, DOES NOT CHANGE current tableName
  void rename(const CVPair colValPair);
  string toString();
};

#endif //RELATION_H
