#ifndef _CALC_H_
#define _CALC_H_

#include <string>
#include <istream>
#include <sstream>


class Calc {
public:
    Calc() {}
    void run();
    double compute(const std::string& str);
    double nextExpr(std::stringstream& str);
    double nextValue(std::stringstream& str);
};
#endif //_CALC_H_
