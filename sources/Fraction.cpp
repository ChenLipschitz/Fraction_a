#include "Fraction.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

////////constructors////////
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

}

////////convert methods////////
Fraction Fraction::convertToFraction(float num){
    return Fraction();
}
Fraction Fraction::convertToFraction(int num){
    return Fraction();
}

int Fraction::gcd(int num1, int num2){
    if (num2 == 0){
        return num1;
    }
    return gcd(num2, num1%num2);
}

////////getters & setters////////
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

////////arithmetic operators////////
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

////////comparison operators////////
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

////////increment and decrement methods////////
Fraction& Fraction::operator++() const{
    int temp = this->denominator+this->numerator;
    setNumerator(temp);
    int gcd_val = Fraction::gcd(numerator, denominator);
    numerator /= gcd_val;
    denominator /= gcd_val;
    return *this;
}
