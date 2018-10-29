#include "row.h"
#include <sstream>

//constructor: adds cell values to vector
Row::Row(vector<string> newVals) {
  for (unsigned int i=0; i < newVals.size(); i++) {
    cellVals.push_back(newVals[i]);
  }
}

string Row::toString() const {
  stringstream os;
  os << "\t";
  for (unsigned int i=0; i < cellVals.size(); i++) {
    os << cellVals[i] << "\t";
  }
  return os.str();
}

string Row::getStartingCell() const{
  return cellVals[0];
}
