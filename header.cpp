#include "header.h"
#include <sstream>

//constructor: adds column names to vector
Header::Header(vector<string> newNames) {
  for (unsigned int i=0; i < newNames.length(); i++) {
    names.push_back(newNames[i]);
  }
}

//toString function: returns each element of the vector
string Header::toString() {
  stringstream os;
  for (unsigned int i=0; i < names.length(); ++i) {
    os << "\t" << names[i];
  }
  return os.str();
}
