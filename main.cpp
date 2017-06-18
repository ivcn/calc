#include <iomanip>
#include <iostream>
#include <math.h>

#include <calc.h>

using namespace std;

int main() {
    Calc calc;
    string input;
    double result = 0.0;
    while(true) {
        cout << "Enter arithmetic expression. Enter 'q' for exit\n";
        getline(cin, input);
        if(input == "q")
            break;
        try{
            result = calc.compute(input);
        }
        catch(runtime_error ex) {
            cerr << "Wrong input. " << ex.what() << endl;
            continue;
        }
        double dummy;
 	    cout << fixed << (modf(result, &dummy) ? setprecision(2) : setprecision(0)) << result << endl;
    }
}
