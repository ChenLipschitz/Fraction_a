#pragma once
#include <iostream>

using namespace std;
namespace ariel{
    class Fraction{
        public:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(float num);
        Fraction(Fraction&& frac);
        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator_);
        void setDenominator(int denominator_);
        
        //arithmetic operators
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;
        
        
        //comparison operators
        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        
        //increment and decrement methods
        Fraction& operator++() const;
        Fraction operator++(int) const;
        Fraction& operator--() const;
        Fraction operator--(int) const;

        //output/input objects to an/from ostream object
        //information for the following methods was taken from-
        //https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
        friend ostream& operator<<(ostream& os, const Fraction& obj);
        friend ostream& operator>>(ostream& os, const Fraction& f);
        
        int gcd(int num1, int num2);
        Fraction convertToFraction(float num);
        Fraction convertToFraction(int num);

        private:
        int numerator;
        int denominator;
    };

}