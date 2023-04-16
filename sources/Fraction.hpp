#pragma once
#include <iostream>
using namespace std;
namespace ariel{
    class Fraction{
        public:
        Fraction(int numerator, int denominator);
        int getNumerator();
        int getDenominator();
        //overloading + operator
        Fraction operator+(const Fraction& other) const;
       //overloading - operator
        Fraction operator-(const Fraction& other) const;
        //overloading * operator
        Fraction operator*(const Fraction& other) const;
        //overloading / operator
        Fraction operator/(const Fraction& other) const;
        //overloading == operator
        Fraction operator==(const Fraction& other) const;
        //overloading ++ prefix operator
        Fraction& operator++() const;
        //overloading ++ postfix operator
        Fraction operator++() const;
        //overloading -- prefix operator
        Fraction& operator--() const;
        //overloading -- postfix operator
        Fraction operator--() const;

        
        private:
        int numerator;
        int denominator;
    };

}