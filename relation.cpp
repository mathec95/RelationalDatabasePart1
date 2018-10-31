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
Relation Relation::select(const vector<CVPair> cvpList) {
  Relation tempRelation("temp", columnNames.getNames());
  for (Row i : rows) {
    bool keep = false;
    for (unsigned int j=0; j < cvpList.size(); j++) {
      if (i.valueExists(cvpList[j])) {
        keep = true;
      }
      else {
        keep = false;
      }
    }
    if (keep) {
      tempRelation.insertRow(i.getCellVals());
    }
  }
  return tempRelation;
}

//select function: keeps rows where given columns have same value
Relation Relation::select(const vector<CCPair> ccpList) {
  Relation tempRelation("temp", columnNames.getNames());
//  set<Row> tempset;
  for (Row i : rows) {
    bool keep = false;
    for (unsigned int j=0; j < ccpList.size(); j++) {
      if (i.pairExists(ccpList[j])) {
        keep = true;
      }
      else {
        keep = false;
        break;
      }
    }
    if (keep) {
      tempRelation.insertRow(i.getCellVals());
    }
  }
  return tempRelation;
}

//rename function: changes the name of column to the given value
void Relation::rename(const CVPair colValPair) {
  columnNames.rename(colValPair);
}

Relation Relation::project(const vector<int> columnsToKeep) {
  vector<string> tempNames;
  for (unsigned int i=0; i < columnsToKeep.size(); i++) {
    tempNames.push_back(columnNames.atIndex(columnsToKeep[i]));
  }
  Relation tempRelation("temp", tempNames);
  for (Row i : rows) {
    vector<string> currentCellVals = i.getCellVals();
    vector<string> tempCellVals;
    for (unsigned int j=0; j < columnsToKeep.size(); j++) {
      string tempVal = currentCellVals.at(columnsToKeep[j]);
      tempCellVals.push_back(tempVal);
    }
    tempRelation.insertRow(tempCellVals);
  }
  return tempRelation;
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
