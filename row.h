/*
data members:
vector<string> (cell values, must be kept in same order as columns)
*/


#ifndef ROW_H
#define ROW_H
#include "cvpair.h"
#include "ccpair.h"
#include <vector>
#include <string>

using namespace std;

class Row {
private:
  vector<string> cellVals;
public:
  Row(const vector<string> newVals);
  ~Row()=default;
  string toString() const;
  string getStartingCell() const;
  vector<string> getCellVals() const;
  bool valueExists(const CVPair colValPair) const;
  bool pairExists(const CCPair colColPair) const;
  bool operator<(const Row temp) const{
    vector<string>tempCellVals = temp.getCellVals();
    bool lessThan = false;
    for (unsigned int i=0; i < tempCellVals.size(); i++) {
      if (cellVals[i] < tempCellVals[i]) {
        lessThan = true;
      }
    }
    return lessThan;
  };
};

#endif //ROW_H
