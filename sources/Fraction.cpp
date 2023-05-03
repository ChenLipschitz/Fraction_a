#include "Fraction.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

//-------------------------- constructors --------------------------//
Fraction::Fraction(){
    //by default create 0
    this->numerator = 0;
    this->denominator = 1;
}
Fraction::Fraction(int numerator_, int denominator_){
    this->numerator = numerator_;
    this->denominator = denominator_;
}
Fraction::Fraction(float num){
    this->numerator = 0;
    this->denominator = 1;
    // int num_digits = 1;
    // float temp = num;
    // while (temp < 1) {
    //     temp *= 10;
    //     num_digits *= 10;
    // }
    // Fraction(static_cast<int>(temp), num_digits);
}
Fraction::Fraction(const Fraction& other) {
    // Copy constructor
    this->numerator = other.getNumerator();
    this->denominator = other.getDenominator();
}

//-------------------------- convert method --------------------------//
Fraction Fraction::convertToFraction(float num){
    return Fraction();
}

int Fraction::gcd(int num1, int num2){
    if (num2 == 0){
        return num1;
    }
    return gcd(num2, num1%num2);
}

//-------------------------- getters & setters --------------------------//
int Fraction::getNumerator() const{
    return this->numerator;
}
int Fraction::getDenominator() const{
    return this->denominator;
}
void Fraction::setNumerator(int numerator_){
    this->numerator = numerator_;
}
void Fraction::setDenominator(int denominator_){
    this->denominator = denominator_;
}

//---------- arithmetic operators: fraction operator fraction ----------//
Fraction Fraction::operator+(const Fraction& other) const{
  return Fraction();  
} 
Fraction Fraction::operator-(const Fraction& other) const{
    return Fraction();
}
Fraction Fraction::operator*(const Fraction& other) const{
    return Fraction();
}
Fraction Fraction::operator/(const Fraction& other) const{
    return Fraction();
}

//---------- arithmetic operators: fraction operator float ----------//
Fraction Fraction::operator+(const float& other) const{
  return Fraction();  
} 
Fraction Fraction::operator-(const float& other) const{
    return Fraction();
}
Fraction Fraction::operator*(const float& other) const{
    return Fraction();
}
Fraction Fraction::operator/(const float& other) const{
    return Fraction();
}

//----------------------- comparison operators -----------------------//
bool Fraction::operator==(const Fraction& other) const{
    return true;
}
bool Fraction::operator!=(const Fraction& other) const{
    return true;
}
bool Fraction::operator>(const Fraction& other) const{
    return true;
}
bool Fraction::operator>=(const Fraction& other) const{
    return true;
}
bool Fraction::operator<(const Fraction& other) const{
    return true;
}
bool Fraction::operator<=(const Fraction& other) const{
    return true;
}

//----------------- increment and decrement methods -----------------//
Fraction& Fraction::operator++(){
    int temp = this->denominator + this->numerator;
    setNumerator(temp);
    int gcd_val = gcd(numerator, denominator);
    numerator /= gcd_val;
    denominator /= gcd_val;
    return *this;
}
Fraction Fraction::operator++(int){
    return Fraction();
}
Fraction& Fraction::operator--(){
    return *this;
}
Fraction Fraction::operator--(int){
    return Fraction();
}

