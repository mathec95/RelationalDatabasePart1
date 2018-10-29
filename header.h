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
  Header(vector<string> newNames);
  ~Header()=default;
  string toString();
};

#endif //HEADER_H
