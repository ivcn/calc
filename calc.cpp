#include <iostream>
#include <sstream>
#include <stdexcept>

#include "calc.h"

using namespace std;

double Calc::compute(const string& s) {
    return nextExpr(std::move(stringstream(s)));
}

double Calc::nextExpr(stringstream&& str) {
    double result = nextValue(str);
    char op;
    //if the next symbol is closing bracket, 
    //this is the end of current expression.
    //It will be consumed by caller.
    while((op = str.peek()) != EOF && op != ')') {
        str.get();
        //consume whitespaces before operator symbol
        if(op == ' ') {
            continue;
        }
        double op2 = 0.0;
        if(op == '*' || op == '/') {
            op2 = nextValue(str);
        }
        else {
            op2 = nextExpr(std::move(str));
        }
        switch(op) {
            case '*':
                result *= op2;
                break;
            case '/':
                result /= op2;
                break;
            case '+':
                result += op2;
                break;
            case '-':
                result -= op2;
                break;
            default:
                throw runtime_error(string("Unknown operation: ") + op);
        }
    }
    return result;
}

double Calc::nextValue(stringstream& str) {
    char c;
    //consume whitespaces before number
    while((c = str.peek()) == ' ') {
        str.get();
        continue;
    }
    //if this is expression in parentheses, go in
    if(c == '(') {
	    str.get();
	    double ret = nextExpr(std::move(str));
        //consume conjugate bracket
        if(str.get() != ')') {
            throw runtime_error("Expected ')'");
        }
        return ret;
    }

    string number;
    if (c == '+') {
        //skip '+' before number
        c = str.get();
    }
    else if (c == '-') {
        //negative number
        number += str.get();
    }
    //parse number
    while((c = str.peek()) && (isalnum(c) || c == '.' || c == ',')) {
	    if (c == ',') {
	        number += '.';
	        str.get();
	    }
	    else {
	        number += str.get();
	    }
    }
    //try to convert string to double
    double result = 0.0;
    try {
        result = stof(number);
    }
    catch(invalid_argument ex) {
        throw runtime_error(string("Invalid expression '") + number + string("'"));
    }
    return result;
}
