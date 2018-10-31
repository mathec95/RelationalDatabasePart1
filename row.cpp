#include "row.h"
#include <sstream>

//constructor: adds cell values to vector
Row::Row(vector<string> newVals) {
  for (unsigned int i=0; i < newVals.size(); i++) {
    cellVals.push_back(newVals[i]);
  }
}

//toString function: returns all values in row as a string
string Row::toString() const {
  stringstream os;
  os << "\t";
  for (unsigned int i=0; i < cellVals.size(); i++) {
    os << cellVals[i] << "\t";
  }
  return os.str();
}

//getStartingCell function: return the first value (for sorting)
string Row::getStartingCell() const{
  return cellVals[0];
}

//getCellVals function: returns cel values as a vector of strings
vector<string> Row::getCellVals() const{
  return cellVals;
}

// valueExists function: checks for a column Value Pair in the row
bool Row::valueExists(const CVPair colValPair) const{
  if (cellVals[colValPair.getCol()] == colValPair.getVal()) {
    return true;
  }
  return false;
}

bool Row::pairExists(const CCPair colColPair) const{
  if (cellVals[colColPair.getCol1()] == cellVals[colColPair.getCol2()]) {
    return true;
  }
  return false;
}
