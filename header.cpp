#include "header.h"
#include <sstream>

//constructor: adds column names to vector
void Header::setNames(vector<string> newNames) {
  for (unsigned int i=0; i < newNames.size(); i++) {
    names.push_back(newNames[i]);
  }
}

//rename function: changes column name at index to given value
void Header::rename(const CVPair colValPair) {
  names[colValPair.getCol()] = colValPair.getVal();
}

//getNames function: returns the names as a vector of strings
vector<string> Header::getNames() const {
  return names;
}

//atIndex function: returns string at given index
string Header::atIndex(int index) const{
  return names[index];
}
//toString function: returns each element of the vector
string Header::toString() {
  stringstream os;
  for (unsigned int i=0; i < names.size(); ++i) {
    os << "\t" << names[i];
  }
  return os.str();
}
