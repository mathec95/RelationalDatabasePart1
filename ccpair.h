#ifndef CCPAIR_H
#define CCPAIR_H

//using namespace std;

class CCPair {
private:
  int column1;
  int column2;
public:
  CCPair(const int tempCol1, const int tempCol2);
  int getCol1() const;
  int getCol2() const;
};

#endif //CCPAIR_H
