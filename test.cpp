#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "calc.h"

Calc calc;

TEST_CASE("1", "") {
    REQUIRE(calc.compute("1") == 1.0);
    REQUIRE(calc.compute(" 1") == 1.0);
    REQUIRE(calc.compute("1 ") == 1.0);
}

TEST_CASE("-1", "") {
    REQUIRE(calc.compute("-1") == -1.0);
    REQUIRE(calc.compute(" -1") == -1.0);
    REQUIRE(calc.compute("-1 ") == -1.0);
}

TEST_CASE("addition", "") { 
    REQUIRE(calc.compute("1+1") == 2.0);
    REQUIRE(calc.compute("1 + 1") == 2.0);
    REQUIRE(calc.compute("1 +1") == 2.0);
    REQUIRE(calc.compute("1+ 1") == 2.0);
}

TEST_CASE("Addition with negative numbers", "") {
    REQUIRE(calc.compute("1+-1") == 0.0);
    REQUIRE(calc.compute("1+ -1") == 0.0);
    REQUIRE(calc.compute("1 +-1") == 0.0);
    REQUIRE(calc.compute("1 + -1") == 0.0);

    REQUIRE(calc.compute("-1+1") == 0.0);
    REQUIRE(calc.compute("-1+ 1") == 0.0);
    REQUIRE(calc.compute("-1 +1") == 0.0);
    REQUIRE(calc.compute("-1 +1") == 0.0);
}

TEST_CASE("Subtraction", "") {
    REQUIRE(calc.compute("7-4") == 3.0);
    REQUIRE(calc.compute("7- 4") == 3.0);
    REQUIRE(calc.compute("7 -4") == 3.0);
    REQUIRE(calc.compute("7 - 4") == 3.0);
}
TEST_CASE("Subtraction with negative numbers", "") {
    REQUIRE(calc.compute("-7-3") == -10.0);
    REQUIRE(calc.compute("-7- 3 ") == -10.0);
    REQUIRE(calc.compute("-7 -3") == -10.0);
    REQUIRE(calc.compute("-7 - 3") == -10.0);

    REQUIRE(calc.compute("-5--5") == 0.0);
    REQUIRE(calc.compute("-5- -5") == 0.0);
    REQUIRE(calc.compute("-5 --5") == 0.0);
    REQUIRE(calc.compute("-5 - -5") == 0.0);
}

TEST_CASE("Multiplication","") {
    REQUIRE(calc.compute("6*7") == 42.0);
    REQUIRE(calc.compute("6* 7") == 42.0);
    REQUIRE(calc.compute("6 *7") == 42.0);
    REQUIRE(calc.compute("6 * 7") == 42.0);
}

TEST_CASE("Multiplication with negative numbers", "") {
    REQUIRE(calc.compute("-10*-10") == 100.0);
    REQUIRE(calc.compute("-10* -10") == 100.0);
    REQUIRE(calc.compute("-10 *-10") == 100.0);
    REQUIRE(calc.compute("-10 * -10") == 100.0);
}

TEST_CASE("Dividing", "") {
    REQUIRE(calc.compute("10/2") ==  5.0);
    REQUIRE(calc.compute("10/ 2") == 5.0);
    REQUIRE(calc.compute("10 /2") == 5.0);
    REQUIRE(calc.compute("10 / 2") == 5.0);
}

TEST_CASE("Dividing with negative  numbers","") {
    REQUIRE(calc.compute("-500/-10") == 50);
    REQUIRE(calc.compute("-500/ -10") == 50);
    REQUIRE(calc.compute("-500 /-10") == 50);
    REQUIRE(calc.compute("-500 / -10") == 50);
}

TEST_CASE("Simple non-integer computations","") {
    REQUIRE(calc.compute("5/4") == 1.25);
    REQUIRE(calc.compute("5.0 /4") == 1.25);
    REQUIRE(calc.compute("5/ 4.0") == 1.25);
    REQUIRE(calc.compute("5.0 / 4.0") == 1.25);

    REQUIRE(calc.compute("5,5") == 5.5);
    REQUIRE(calc.compute("5,5 *4") == 22);
    REQUIRE(calc.compute("5,5* 4,0") == 22);
    REQUIRE(calc.compute("5,5 * 4,0") == 22);
    
}

TEST_CASE("Additive and multiplicative operators priority", "") {
    REQUIRE(calc.compute("2 + 2 * 2") == 6);
    REQUIRE(calc.compute("2 * 2 + 2") == 6);
    REQUIRE(calc.compute("5,5 * 2.0 + 124 * 0.5") == 73);

    REQUIRE(calc.compute("100.0/2 * 3") == 150);
    REQUIRE(calc.compute("6/2/3") == 1);
    REQUIRE(calc.compute("30.5*2-1") == 60);
}

TEST_CASE("Check working with parentheses", "") {
    REQUIRE(calc.compute("(2+2)*2") == 8);
    REQUIRE(calc.compute("2+(2+2)") == 6);
    REQUIRE(calc.compute("(3,3+1.2)*(5,5-0.5)") == 22.5);
    REQUIRE(calc.compute("(128+32) / (150 - 11 * 2)") == 1.25);
}
