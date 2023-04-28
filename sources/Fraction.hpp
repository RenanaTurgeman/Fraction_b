#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <cmath>

// using namespace std;

namespace ariel{
class Fraction {
    private:
        int numerator; //above
        int denominator;
        void reduce();
        // Recursive function to
    // return GCD of a and b
    long long gcd(long long numa, long long numb);
    public:
        // Constructors
        Fraction();
        Fraction(int num , int den );
        Fraction(float number);
        //copy consructtor
        // Fraction(const Fraction& other);
        // ~Fraction()= default;
        //geters
        int getNumerator() const;
        int getDenominator() const;
        // Overloaded operators
        friend Fraction operator+(const Fraction& num1, const Fraction& num2);
        friend Fraction operator-(const Fraction& num1, const Fraction& num2);
        friend Fraction operator*(const Fraction& num1, const Fraction& num2);
        friend Fraction operator/(const Fraction& num1, const Fraction& num2);
        friend bool operator==(const Fraction& num1, const Fraction& num2);
        friend bool operator!=(const Fraction& num1, const Fraction& num2);
        friend bool operator>(const Fraction& num1, const Fraction& num2);
        friend bool operator<(const Fraction& num1, const Fraction& num2);
        friend bool operator>=(const Fraction& num1, const Fraction& num2);
        friend bool operator<=(const Fraction& num1, const Fraction& num2);

        Fraction& operator++(); // prefix increment
        const Fraction operator++(int); // postfix increment
        Fraction& operator--(); // prefix decrement
        const Fraction operator--(int); // postfix decrement
        friend std::ostream& operator<<(std::ostream& output, const Fraction& frac);
        friend std::istream& operator>>(std::istream& input, Fraction& frac);
};

};
#endif
