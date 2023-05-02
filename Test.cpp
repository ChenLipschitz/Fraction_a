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
    Fraction frc4(0.0);
    CHECK_THROWS(frc1/frc2);
    CHECK_NOTHROW(frc2/frc1);
    CHECK_THROWS(frc2/frc3);
    CHECK_THROWS(frc2/frc4);    
}

TEST_CASE("0 as a denominater or numerator test"){
    CHECK_THROWS(Fraction(0,0));
    CHECK_THROWS(Fraction(0.0));
    CHECK_NOTHROW(0);
}

Test_Case("gcd test"){
    int num1 = 4;
    int num2 = 8;
    int num3 = 0;
    int num4 = -6;
    int gcd1 = gcd(num1,num2);
    int gcd2 = gcd(num1,num3);
    int gcd3 = gcd(num2,num4);
    int gcd4 = gcd(num4,num4);
    CHECK(gcd1 == 4);
    CHECK(gcd2 == 4);
    CHECK(gcd3 == 2);
    CHECK(gcd4 == 6);
}

TEST_CASE("Arithmetic operators test"){
    Fraction frc1(9,8);
    Fraction frc2(0);
    Fraction frc3(2.346);

}

Test_Case("Input/output streams test"){

}

Test_Case("Getters & setters test"){
    Fraction frc1(9,8);
    Fraction frc2(0);
    Fraction frc3(2.346);
    CHECK(frc2.getDenominater() == 1);
    CHECK(frc3.getDenominater() == 1);
    CHECK(frc1.setNumerator(16));
    CHECK(frc1.getNumerator() == 2);
}

Test_Case("Order of operations test"){
    Fraction frc1(9,8);
    Fraction frc2(7,1);
    Fraction frc3(86);
    Fraction frc4(45.556);
    //commutative
    CHECK(frc1 + frc2 == frc2 + frc1);
    CHECK(frc3 * frc4 == frc4 * frc3);
    CHECK(frc1 - frc2 != frc2 - frc1);
    CHECK(frc1 + frc2 * frc3 - frc4v /frc1 == frc2 * frc3 - (frc4v /frc1) + frc1);
    CHECK(frc1 * frc2 / frc3 == frc2 / frc3 *frc1);
    //associative
    CHECK((frc1 + frc2)*frc3 == frc1*frc3 + frc2*frc3);
    CHECK((frc1 - frc2)*frc3 == frc1*frc3 - frc2*frc3);
    CHECK((frc1 + frc2)/frc3 == frc1/frc3 + frc2/frc3);
    CHECK((frc1 - frc2)/frc3 == frc1/frc3 - frc2/frc3);
    
}

Test_Case("Increment and decrement methods test"){
    Fraction frc1(9,8);
    Fraction copyFrc1(frc1);
    Fraction frc2(0);
    Fraction frc3(2.346);
    frc1.setNumenator(frc1.getNumenator()+frc1.getDenominator());
    frc1.setDenominator(frc1.getDenominator()+frc1.getDenominator());
    copyFrc1++;
    CHECK(frc1 == copyFrc1);
    frc2--;
    CHECK(frc2 == Fraction(-1));
    ++frc3;
    --frc1;
    /// RETURN TO HERE /////
}

TEST_CASE("Comparison operators test"){

}