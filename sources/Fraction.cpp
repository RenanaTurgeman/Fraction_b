#include "Fraction.hpp"
#include <limits> //for handle overflow cheks
using namespace std;

namespace ariel{
    /*Constructors:*/ 
    Fraction::Fraction(): numerator(0), denominator(1){}
    
    Fraction::Fraction(int num , int den) : numerator(num), denominator(den) {
        if(denominator == 0){ // If denominator is zero- its illegal
            throw invalid_argument("ERROR: denominator cant be zero");
        }
        this->reduce();
    }
    
    //needed for it to fit the test
    Fraction::Fraction(float number):numerator(1000*number),denominator(1000){
        // Convert the float to fraction by multiplying the numerator by 1000 and the denominator by 1000
        // Then reduce the fraction
        this->reduce();
    }

    /*Reduce the fraction to its simplest form*/
    void Fraction::reduce() {
        // Calculate the GCD of the numerator and denominator using the built-in __gcd() function
        int gcd = __gcd(abs(this->numerator), abs(this->denominator));
        // Divide both numerator and denominator by the GCD to get the simplified fraction
        this->numerator /= gcd;
        this->denominator /= gcd;
        // If the denominator is negative, change the signs of both numerator and denominator
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    /*getters:*/
    int Fraction::getNumerator() const{
        return this->numerator;
    }
    int Fraction::getDenominator() const{
        return this->denominator;
    }

    /*Overloaded operators:*/ 
    Fraction operator+(const Fraction& num1, const Fraction& num2){
        // Calculate the numerator and denominator of the sum.
        long long num = (long long)num1.getNumerator() * num2.getDenominator() + (long long)num2.getNumerator() * num1.getDenominator();
        long long den = (long long)num1.getDenominator() * num2.getDenominator();
       
        // Check for overflow by comparing with the minimum and maximum values of an int
        int min_val = numeric_limits<int>::min();
        int max_val = numeric_limits<int>::max();


        if (num > max_val || num < min_val)
        {
            throw overflow_error("ERROR: overflow occurred during addition");
        }
        if (den > max_val || den < min_val)
        {
            throw overflow_error("ERROR: overflow occurred during addition");
        }

        Fraction result((int)num, (int)den);
        return result;
    }

    Fraction operator-(const Fraction& num1, const Fraction& num2){
        // Calculate the numerator and denominator of the sub.
        long long num = (long long)num1.getNumerator() * num2.getDenominator() - (long long)num2.getNumerator() * num1.getDenominator();
        long long den = (long long)num1.getDenominator() * num2.getDenominator();
        
        // Check for overflow by comparing with the minimum and maximum values of an int
        int min_val = numeric_limits<int>::min();
        int max_val = numeric_limits<int>::max();

        if (num > max_val || num < min_val)
        {
            throw overflow_error("ERROR: overflow occurred during addition");
        }
        if (den > max_val || den < min_val)
        {
            throw overflow_error("ERROR: overflow occurred during addition");
        }

        Fraction result((int)num, (int)den);
        result.reduce();
        return result;
    }

    Fraction operator*(const Fraction& num1, const Fraction& num2) {
        // If any of the fractions is 0, then the answer is 0
        if (num1.getNumerator() == 0 || num2.getNumerator() == 0) {
            return Fraction(0);
        }
    
        // Check for overflow when multiplying the numerator of the two fractions
        // If one of the numerators is the minimum integer value, then multiplication will cause overflow
        int min_val = numeric_limits<int>::min();


        if (num1.getNumerator() == min_val || num2.getNumerator() == min_val) {
            throw overflow_error("ERROR: overflow occurred during multiplication");
        }
        // Check for overflow when multiplying the two fractions' numerators and denominators
        // Check if the numerator of one fraction is larger than the maximum integer value divided by the other fraction's denominator
        // This means that when the numerators are multiplied, the result would be larger than the maximum integer value, causing overflow
        int max_val = numeric_limits<int>::max();

        if (num1.getNumerator() > max_val / num2.getDenominator() || num2.getNumerator() > max_val / num1.getDenominator()) {
            throw overflow_error("ERROR: overflow occurred during multiplication");
        }

        // Calculate the numerator and denominator of the answer fraction
        int num = num1.getNumerator() * num2.getNumerator();
        int den = num1.getDenominator() * num2.getDenominator();

        Fraction result(num, den);
        result.reduce();
        return result;
    }
    
    Fraction operator/(const Fraction &num1, const Fraction &num2){
    
        if (num2.getNumerator() == 0){
            throw runtime_error("ERROR: ilegal divison by 0");
        }

        long long num = (long long) num1.getNumerator() * (long long) num2.getDenominator(); 
        long long den = (long long) num1.getDenominator() * (long long) num2.getNumerator();
    
        int min_val = numeric_limits<int>::min();
        int max_val = numeric_limits<int>::max();

        if (num > max_val || num < min_val) {
            throw overflow_error("ERROR: Overflow occurred during division");
        }
        if (den > max_val || den < min_val) {
            throw overflow_error("ERROR: Overflow occurred during division");
        }

        Fraction result((int) num, (int) den);
        return result;

    }   


    bool operator==(const Fraction& num1, const Fraction& num2){
        // first multiplies the numerator of each fraction by 1000 and divides by the denominator, 
        // keeping only the three digits after the decimal point.
        int digits1 = (int)(num1.getNumerator() * 1000 / num1.getDenominator()) % 1000;
        int digits2 = (int)(num2.getNumerator() * 1000 / num2.getDenominator()) % 1000;
        return digits1 == digits2;
    }

    bool operator!=(const Fraction& num1, const Fraction& num2) {
        
        int digits1 = num1.getNumerator() * num2.getDenominator();
        int digits2 = num2.getNumerator() * num1.getDenominator();
        return digits1 != digits2;
    }


    bool operator>(const Fraction& num1, const Fraction& num2){
        return num1.getNumerator() * num2.getDenominator() > num2.getNumerator() * num1.getDenominator();
    }

    bool operator<(const Fraction& num1, const Fraction& num2){
        return num1.getNumerator() * num2.getDenominator() < num2.getNumerator() * num1.getDenominator();
    }

    bool operator>=(const Fraction& num1, const Fraction& num2){
        return num1>num2 || num1==num2;
    }

    bool operator<=(const Fraction& num1, const Fraction& num2){
        return num1<num2 || num1==num2;
    }

    Fraction& Fraction::operator++(){ // prefix increment
        if (numerator > numeric_limits<int>::max()) {
            throw overflow_error("Error: overflow occurred!") ;
        } else {
            numerator += denominator;
            this->reduce();
        }

        return *this;
    }

    const Fraction Fraction::operator++(int){ // postfix increment
        Fraction result = *this; //save it for return the object before the changes
        ++(*this );
        this->reduce();
        return result;
    }

    Fraction& Fraction::operator--(){ // prefix decrement
        if (numerator < numeric_limits<int>::min()) {
            throw overflow_error("Error: overflow occurred!") ;
        } else {
            numerator -= denominator;
            this->reduce();
        }

        return *this;
    }


    const Fraction Fraction::operator--(int){ // postfix decrement
        Fraction result = *this; //save it for return the object before the changes
        --(*this);
        this->reduce();
        return result;    
    }

    std::ostream& operator<<(std::ostream& output, const Fraction& frac){
        output << frac.numerator <<'/' << frac.denominator;
        return output;    
    }

    std::istream& operator>>(std::istream& input, Fraction& frac){
         int numerator ,denominator;

         input>>numerator>>denominator;
         if(input.fail()){ //determine if a failuire has occurred on the input stream
            throw runtime_error("ilegal input");
         }

         if( (denominator != 0)){ //if it is legal
            frac.numerator =numerator;
            frac.denominator = denominator;
            frac.reduce();
         }else{ //denominator =0
            throw runtime_error("denominator can't be zero");
         } 

         return input;
    }

}