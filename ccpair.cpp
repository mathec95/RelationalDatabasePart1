#include "ccpair.h"

CCPair::CCPair(const int tempCol1, const int tempCol2) {
  column1 = tempCol1;
  column2 = tempCol2;
}

int CCPair::getCol1() const {
  return column1;
}

int CCPair::getCol2() const {
  return column2;
}
