#include <iomanip>
#include <iostream>

#include <calc.h>




int main() {
    Calc calc;
    std::string input;
    std::cout << "Enter arithmetic expression. Enter 'q' for exit\n";
    while(getline(std::cin, input)) {
        if(input == "q")
            break;
        double result = calc.compute(input);
	std::cout << std::fixed << std::setprecision(2) << result << std::endl;
	std::cout << "Enter arithmetic expression. Enter 'q' for exit\n";
    }
}
