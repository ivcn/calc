#ifndef _CALC_H_
#define _CALC_H_

#include <istream>
#include <sstream>
#include <string>

class Calc {
  public:
    double compute(const std::string &str);

  private:
    double nextExpr(std::stringstream &&str);
    double nextValue(std::stringstream &str);
};
#endif //_CALC_H_
