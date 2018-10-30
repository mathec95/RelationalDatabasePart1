#include "relation.h"
#include <sstream>

//constructor: adds name and columns
Relation::Relation(string newName, vector<string> newColumns) {
  tableName = newName;
  columnNames.setNames(newColumns);
}

//insertRow function: adds row to set
void Relation::insertRow(const vector<string> newRow) {
  Row temp(newRow);
  rows.insert(temp);
}

//select function: keeps rows that have given values in them
void Relation::select(const vector<CVPair> cvpList) {
  set<Row> tempSet;
  for (set<Row>::iterator it=rows.begin(); it!=rows.end(); it++) {
    bool keep = false;
    for (unsigned int i=0; i < cvpList.size(); i++) {
      if (it->valueExists(cvpList[i])) {
        keep = true;
      }
      else {
        keep = false;
      }
    }
    if (keep) {
      Row tempRow = *it;
      tempSet.insert(tempRow);
    }
  }
  rows.clear();
  rows = tempSet;
}

//select function: keeps given columns
void Relation::select(const vector<CCPair> ccpList) {
  Header tempHeader;
  vector<int> deleteVec = {};
  for (unsigned int i=0; i < ccpList.size(); i++) {
    deleteVec.push_back(ccpList[i].)
  }
}
//rename function: changes the name of column to the given value
void Relation::rename(const CVPair colValPair) {
  columnNames.rename(colValPair);
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
