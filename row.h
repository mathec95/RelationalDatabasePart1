/*
data members:
vector<string> (cell values, must be kept in same order as columns)
*/


#ifndef ROW_H
#define ROW_H
#include <vector>
#include <string>

using namespace std;

class Row {
private:
  vector<string> cellVals;
public:
  Row(vector<string> newVals);
  ~Row()=default;
  string toString();
};

#endif //ROW_H
