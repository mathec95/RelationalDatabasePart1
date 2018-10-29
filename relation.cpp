#include "relation.h"
#include <sstream>

//constructor: adds name and columns
Relation::Relation(string newName, vector<string> newColumns) {
  tableName = newName;
  columnNames.setNames(newColumns); //this might not work, maybe use a pointer
}

//insertRow function: adds row to set
void Relation::insertRow(const vector<string> newRow) {
  Row temp(newRow);
  rows.insert(temp); //this might not work, syntax might be wrong
}

//toString function: prints relation in a table form
string Relation::toString() {
  stringstream os;
  os << tableName << endl;
  os << columnNames.toString() << endl;
  for (set<Row>::iterator it=rows.begin(); it!=rows.end(); it++) {
    os << it->toString() << endl;
  }
  return os.str();
}
