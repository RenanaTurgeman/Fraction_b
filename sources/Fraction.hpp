#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <cmath>
#include <limits>

namespace ariel{
class Fraction {
    private:
        int numerator; // Numerator of the fraction (above the line)
        int denominator; // Denominator of the fraction (below the line)
        void reduce(); // Reduces the fraction to its simplest form

    public:
        // Constructors
        Fraction(); // Default constructor, creates a fraction with numerator 0 and denominator 1
        Fraction(int num , int den ); // Creates a fraction with given numerator and denominator
        Fraction(float number); // Creates a fraction from a float number

        //geters
        int getNumerator() const; // Returns the numerator of the fraction
        int getDenominator() const; // Returns the denominator of the fraction

        // Overloaded operators
        friend Fraction operator+(const Fraction& num1, const Fraction& num2); // Adds two fractions
        friend Fraction operator-(const Fraction& num1, const Fraction& num2); // Subtracts two fractions
        friend Fraction operator*(const Fraction& num1, const Fraction& num2); // Multiplies two fractions
        friend Fraction operator/(const Fraction& num1, const Fraction& num2); // Divides two fractions
        friend bool operator==(const Fraction& num1, const Fraction& num2); // Compares two fractions for equality
        friend bool operator!=(const Fraction& num1, const Fraction& num2); // Compares two fractions for inequality
        friend bool operator>(const Fraction& num1, const Fraction& num2); // Compares two fractions (greater than)
        friend bool operator<(const Fraction& num1, const Fraction& num2); // Compares two fractions (less than)
        friend bool operator>=(const Fraction& num1, const Fraction& num2); // Compares two fractions (greater than or equal to)
        friend bool operator<=(const Fraction& num1, const Fraction& num2); // Compares two fractions (less than or equal to)

        Fraction& operator++(); // prefix increment
        const Fraction operator++(int); // postfix increment
        Fraction& operator--(); // prefix decrement
        const Fraction operator--(int); // postfix decrement
        friend std::ostream& operator<<(std::ostream& output, const Fraction& frac); // Outputs the fraction to an output stream
        friend std::istream& operator>>(std::istream& input, Fraction& frac); // Reads the fraction from an input stream
};

};
#endif
