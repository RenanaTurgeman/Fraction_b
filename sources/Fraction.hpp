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
    long long gcd(long long a, long long b);
    public:
        // Constructors
        Fraction(int num , int den ) : numerator(num), denominator(den) {}
        Fraction(float number);
        ~Fraction()= default;
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
        friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
        friend std::istream& operator>>(std::istream& is, Fraction& f);
};

};
#endif
