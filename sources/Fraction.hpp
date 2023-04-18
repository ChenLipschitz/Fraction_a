#pragma once
#include <iostream>
using namespace std;
namespace ariel{
    class Fraction{
        public:
        Fraction(int numerator, int denominator);
        int getNumerator();
        int getDenominator();
        
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
        
        private:
        int numerator;
        int denominator;
    };

}