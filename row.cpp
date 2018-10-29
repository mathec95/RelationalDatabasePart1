#include "row.h"
#include <sstream>

//constructor: adds cell values to vector
Row::Row(vector<string> newVals) {
  for (unsigned int i=0; i < newVals.length(); i++) {
    cellVals.push_back(newVals[i]);
  }
}

string Row::toString() {
  stringstream os;
  for (unsigned int i=0; i < cellVals.length(); i++) {
    os << cellVals[i] << "\t";
  }
  return os.str();
}
