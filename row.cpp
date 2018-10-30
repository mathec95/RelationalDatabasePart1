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

// valueExists function: checks for a column Value Pair in the row
bool Row::valueExists(const CVPair colValPair) const{
  if (cellVals[colValPair.getCol()] == colValPair.getVal()) {
    return true;
  }
  return false;
}
