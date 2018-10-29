#ifndef CVPAIR_H
#define CVPAIR_H
#include <string>

using namespace std;

class CVPair {
private:
  int column;
  string value;
public:
  CVPair(const int tempCol, const string tempVal);
  int getCol() const;
  string getVal() const;
};

#endif //CVPAIR_H
