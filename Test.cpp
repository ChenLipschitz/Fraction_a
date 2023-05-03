#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("Deviding by  test"){
    CHECK_NOTHROW(Fraction(2, 68));
    CHECK_THROWS(Fraction(9, 0));
    Fraction frc1(9,8);
    Fraction frc2(0,1);
    Fraction frc3(0);
    Fraction frc4(0.00000);
    CHECK_THROWS(frc1/frc2);
    CHECK_NOTHROW(frc2/frc1);
    CHECK_THROWS(frc2/frc3);
    CHECK_THROWS(frc2/frc4);    
}

TEST_CASE("0 as a denominater or numerator test"){
    CHECK_THROWS(Fraction(0,0));
    CHECK_NOTHROW(Fraction(0.00000));
    CHECK_NOTHROW(Fraction(0));
}

TEST_CASE("gcd test"){
    Fraction frc1(9,8);
    Fraction frc2(83);
    Fraction frc3(-12,9);
    Fraction frc4(4.988);
    int gcd1 = frc1.gcd(frc1.getNumerator(), frc1.getDenominator());
    int gcd2 = frc2.gcd(frc2.getNumerator(), frc2.getDenominator());
    int gcd3 = frc3.gcd(frc3.getNumerator(), frc3.getDenominator());
    int gcd4 = frc4.gcd(frc4.getNumerator(), frc4.getDenominator());
    CHECK(gcd1 == 72);
    CHECK(gcd2 == 1);
    CHECK(gcd3 == 3);
    CHECK(gcd4 == 1);
}

TEST_CASE("Arithmetic operators test"){
    Fraction frc1(9,8);
    Fraction frc2(0);
    Fraction frc3(2.34);
    Fraction frc4(2,1);
    Fraction frc5(8,4);
    Fraction frc6(-2,3);
    Fraction frc7(-3,7);
    SUBCASE("both positive numbers"){
        CHECK((frc1+frc2) == frc1);
        CHECK((frc3-frc4) == Fraction(0.34));
        CHECK((frc3*frc2) == Fraction(0));
        CHECK((frc5/frc4) == Fraction(1,1));
    }
    SUBCASE("2 negativ numbers"){
        CHECK((frc6+frc7) == Fraction(-23,21));
        CHECK((frc6-frc7) == Fraction(-5,21));
        CHECK((frc6*frc7) == Fraction(2,7));
        CHECK((frc6/frc7) == Fraction(14,9));
    }
    SUBCASE("one negative and one positive"){
        CHECK((frc6+frc4) == Fraction(4,3));
        CHECK((frc7-frc1) == Fraction(-87,56));
        CHECK((frc7*frc1) == Fraction(-8,21));
        CHECK((frc6/frc4) == Fraction(-1,3));
    }
}

// TEST_CASE("Input/output streams test"){
//     std::ostringstream ostr1;
//     Fraction frac1(98.434);
//     ostr1 << frac1;
//     CHECK(ostr1.str() == "98434/1000");
//     std::ostringstream ostr2;
//     Fraction frac2(-2,7);
//     ostr2 << frac2;
//     CHECK(ostr2.str() == "-2/7");
//     std::istringstream istr1;
//     Fraction frac3("7/4");
//     istr1 >> frac3;
//     CHECK(istr1.getNumerator() == 7);
//     CHECK(istr1.getDenominator() == 4);
// }

TEST_CASE("Getters & setters test"){
    Fraction frc1(9,8);
    Fraction frc2(0);
    Fraction frc3(2.346);
    CHECK(frc2.getDenominator() == 1);
    CHECK(frc3.getDenominator() == 1);
    frc1.setNumerator(16);
    CHECK_NOTHROW(frc2.setDenominator(56));
    CHECK(frc1.getNumerator() == 2);
}

TEST_CASE("Order of operations test"){
    Fraction frc1(9,8);
    Fraction frc2(7,1);
    Fraction frc3(86);
    Fraction frc4(45.556);
    SUBCASE("commutative"){
        CHECK(frc1 + frc2 == frc2 + frc1);
        CHECK(frc3 * frc4 == frc4 * frc3);
        CHECK(frc1 - frc2 != frc2 - frc1);
        CHECK(frc1 + frc2 * frc3 - frc4 /frc1 == frc2 * frc3 - (frc4 /frc1) + frc1);
        CHECK(frc1 * frc2 / frc3 == frc2 / frc3 *frc1);
    }
    SUBCASE("associative"){
        CHECK((frc1 + frc2)*frc3 == frc1*frc3 + frc2*frc3);
        CHECK((frc1 - frc2)*frc3 == frc1*frc3 - frc2*frc3);
        CHECK((frc1 + frc2)/frc3 == frc1/frc3 + frc2/frc3);
        CHECK((frc1 - frc2)/frc3 == frc1/frc3 - frc2/frc3);
    }
}

TEST_CASE("Increment and decrement methods test"){
    Fraction frc1(9,8);
    Fraction copyFrc1(frc1);
    Fraction frc2(0);
    Fraction frc3(2.346);
    frc1.setNumerator(frc1.getNumerator()+frc1.getDenominator());
    frc1.setDenominator(frc1.getDenominator()+frc1.getDenominator());
    copyFrc1++;
    CHECK(frc1 == copyFrc1);
    frc2--;
    CHECK(frc2 == Fraction(-1));
    ++frc3;
    --frc1;
    CHECK(frc1 != copyFrc1);
    CHECK(frc3 == Fraction(1673,500));
}

TEST_CASE("Comparison operators test"){
    Fraction frc1(9,8);
    Fraction frc2(7,1);
    Fraction frc3(86);
    Fraction frc4(45.556);
    Fraction frc5(14,2);
    CHECK(frc3>frc1);
    CHECK_FALSE(frc1>frc3);
    CHECK(frc2 >= frc1);
    CHECK(frc4<=frc3);
    CHECK(frc4 != frc2);
    CHECK(frc2 == frc5);
    CHECK_FALSE(frc2<frc5);
}
