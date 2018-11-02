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
  Relation();
  Relation(string newName, vector<string> newColumns);
  ~Relation()=default;
  void insertRow(const vector<string> newRow);
  Relation select(const vector<CVPair> cpvList);
  Relation select(const vector<CCPair> ccpList);
  Relation project(const vector<int> columnsToKeep);
  Relation rename(const vector<CVPair> cvpList);
  string toString();
};

#endif //RELATION_H
