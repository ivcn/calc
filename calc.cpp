#include <iostream>
#include <sstream>
#include <stdexcept>

#include "calc.h"

using namespace std;

double Calc::compute(const string& s) {
    stringstream str(s);
    return nextExpr(str);
}

double Calc::nextExpr(stringstream& str) {
    double result = nextValue(str);
    char op;
    while((op = str.get()) != EOF && op != ')') {
        if(op == ' ') {
            continue;
        }
        double op2 = 0.0;
        if(op == '*' || op == '/') {
            op2 = nextValue(str);
        }
        else {
            op2 = nextExpr(str);
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
        }
    }
    return result;
}

double Calc::nextValue(stringstream& str) {
    char c;
    while((c = str.peek()) == ' ') {
        str.get();
        continue;
    }
    //if this is expression in parentheses, go in
    if(c == '(') {
	str.get();
	return nextExpr(str);
    }

    string number;
    if (c == '+') {
        //skip
        c = str.get();
    }
    else if (c == '-') {
        //negative number
        number += str.get();
    }
    
    //parse number
    while((c = str.peek()) && (isalnum(c) || c == '.' || c == ',')){
	if(c == ','){
	    number += '.';
	    str.get();
	}
	else {
	    number += str.get();
	}
    }

    double result = 0.0;
    try {
        result = stof(number);
    }
    catch(invalid_argument ex) {
        throw runtime_error("Wrong input: invalid expression " + number);
    }
    return result;
}
