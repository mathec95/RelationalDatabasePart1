#include "cvpair.h"

CVPair::CVPair(const int tempCol, const string tempVal) {
  column = tempCol;
  value = tempVal;
}

int CVPair::getCol() const {
  return column;
}

string CVPair::getVal() const {
  return value;
}
