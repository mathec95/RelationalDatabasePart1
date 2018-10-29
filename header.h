/*
data members:
vector<string> (list of column names)
*/

#ifndef HEADER_H
#define HEADER_H
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
  string toString();
};

#endif //HEADER_H
