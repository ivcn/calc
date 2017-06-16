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

TEST_CASE("Non-integer computations","") {
    REQUIRE(calc.compute("5/4") == 1.25);
    REQUIRE(calc.compute("5.0 /4") == 1.25);
    REQUIRE(calc.compute("5/ 4.0") == 1.25);
    REQUIRE(calc.compute("5.0 / 4.0") == 1.25);
}

