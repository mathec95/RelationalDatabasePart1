/*
data members:
vector<string> (list of column names)
*/

#ifndef HEADER_H
#define HEADER_H
#include "cvpair.h"
#include <vector>
#include <string>

using namespace std;

class Header {
private:
  vector<string> names;
public:
  Header()=default;
  ~Header()=default;
  void setNames(vector<string> newNames);
  void rename(const CVPair colValPair);
  vector<string> getNames() const;
  string atIndex(int index) const;
  string toString();
};

#endif //HEADER_H
