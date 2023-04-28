#include "Fraction.hpp"
 using namespace std;

namespace ariel{
    // https://www.geeksforgeeks.org/convert-given-decimal-number-into-an-irreducible-fraction/
     Fraction::Fraction(float number){
            // Fetch integral value of the decimal
            double intVal = floor(number);
 
            // Fetch fractional part of the decimal
            double fVal = number - intVal;
 
            // Consider precision value to
            // convert fractional part to
            // integral equivalent
            const long pVal = 1000000000;
 
            // Calculate GCD of integral
            // equivalent of fractional
            // part and precision value
            long long gcdVal = gcd(round(fVal * pVal), pVal);
 
            // Calculate num and deno
            long long num = round(fVal * pVal) / gcdVal;
            long long deno = pVal / gcdVal;
 
            // save the fraction
            numerator=(intVal * deno) + num;
            denominator= deno;
        }
        
    long long Fraction::gcd(long long a, long long b){
        if (a == 0)
            return b;
        else if (b == 0)
            return a;
        if (a < b)
            return gcd(a, b % a);
        else
            return gcd(b, a % b);
    }

    void Fraction::reduce() {
        long long gcd = this->gcd(abs(this->numerator), abs(this->denominator));
        this->numerator /= gcd;
        this->denominator /= gcd;
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    // Overloaded operators:
    Fraction operator+(const Fraction& num1, const Fraction& num2) {
        int num = num1.numerator * num2.denominator + num1.denominator * num2.numerator;
        int den = num1.denominator * num2.denominator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }

    Fraction operator-(const Fraction& num1, const Fraction& num2){
        int num = num1.numerator * num2.denominator - num1.denominator * num2.numerator;
        int den = num1.denominator * num2.denominator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }

    Fraction operator*(const Fraction& num1, const Fraction& num2){
        int num = num1.numerator * num2.numerator;
        int den = num1.denominator * num2.denominator;
        Fraction result(num, den);
        result.reduce();
        return result;    
    }

    Fraction operator/(const Fraction& num1, const Fraction& num2) {
        int num = num1.numerator * num2.denominator ;
        int den = num1.denominator * num2.numerator;
        Fraction result(num, den);
        result.reduce();
        return result;  
    }

    bool operator==(const Fraction& num1, const Fraction& num2){
        return (num1.numerator == num2.numerator) && (num1.denominator ==num2.denominator);
    }
    bool operator!=(const Fraction& num1, const Fraction& num2){
        return !(num1 == num2);
    }

    bool operator>(const Fraction& num1, const Fraction& num2){
        return num1.numerator * num2.denominator > num2.numerator * num1.denominator;
    }

    bool operator<(const Fraction& num1, const Fraction& num2){
        return num1.numerator * num2.denominator < num2.numerator * num1.denominator;
    }

    bool operator>=(const Fraction& num1, const Fraction& num2){
        return num1>num2 || num1==num2;
    }

    bool operator<=(const Fraction& num1, const Fraction& num2){
        return num1<num2 || num1==num2;
    }

    Fraction& Fraction::operator++(){ // prefix increment
        this->numerator = this->numerator + this->denominator;
        this->reduce();
        return *this;
    }

    const Fraction Fraction::operator++(int){ // postfix increment
        Fraction result = *this; //save it for return the object before the changes
        ++(*this );
        this->reduce();
        return result;
    }

    Fraction& Fraction::operator--(){ // prefix decrement
        this->numerator = this->numerator - this->denominator;
        this->reduce();
        return *this;
    }

    const Fraction Fraction::operator--(int){ // postfix decrement
        Fraction result = *this; //save it for return the object before the changes
        --(*this);
        this->reduce();
        return result;    
    }

    std::ostream& operator<<(std::ostream& os, const Fraction& f){
        os << f.numerator <<'/' << f.denominator;
        return os;    
    }

    std::istream& operator>>(std::istream& is, Fraction& f){
         int numerator ,denominator;
         char slash;

         is>>numerator;
         is>>slash;
         is>>denominator;

         if((slash== '/') && (denominator != 0)){ //if it is legal
            f.numerator =numerator;
            f.denominator = denominator;
         }else{
            throw invalid_argument("illigal input");
         } 

         return is;
    }

 
}