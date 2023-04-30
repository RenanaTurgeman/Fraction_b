#include "Fraction.hpp"
#include <limits> //for handle overflow cheks
 using namespace std;

namespace ariel{
    Fraction::Fraction(){
        this->numerator=1;
        this->denominator =1;
    }
    
    Fraction::Fraction(int num , int den) : numerator(num), denominator(den) {
        if(denominator == 0){
            throw invalid_argument("denominator cant be zero");
        }
        this->reduce();
    }
    
    //for it to fit the test
    Fraction::Fraction(float number):numerator(1000*number),denominator(1000){
           this->reduce();
    }

    // copy constructor
    // Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

    long long Fraction::gcd(long long numa, long long numb){
        if (numa == 0)
            return numb;
        else if (numb == 0)
            return numa;
        if (numa < numb)
            return gcd(numa, numb % numa);
        else
            return gcd(numb, numa % numb);
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

    //getters
    int Fraction::getNumerator() const{
        return this->numerator;
    }
    int Fraction::getDenominator() const{
        return this->denominator;
    }

    // Overloaded operators:
    Fraction operator+(const Fraction& num1, const Fraction& num2){
        long long num = (long long)num1.getNumerator() * num2.getDenominator() + (long long)num2.getNumerator() * num1.getDenominator();
        long long den = (long long)num1.getDenominator() * num2.getDenominator();

        if (num > (long long)numeric_limits<int>::max() || num < (long long)numeric_limits<int>::min())
        {
            throw overflow_error("overflow occurred during addition");
        }
        if (den > (long long)numeric_limits<int>::max() || den < (long long)numeric_limits<int>::min())
        {
            throw overflow_error("overflow occurred during addition");
        }

        Fraction result((int)num, (int)den);
        return result;
    }

    Fraction operator-(const Fraction& num1, const Fraction& num2){
        long long num = (long long)num1.getNumerator() * num2.getDenominator() - (long long)num2.getNumerator() * num1.getDenominator();
        long long den = (long long)num1.getDenominator() * num2.getDenominator();
        
        if (num > (long long)numeric_limits<int>::max() || num < (long long)numeric_limits<int>::min())
        {
            throw overflow_error("overflow occurred during addition");
        }
        if (den > (long long)numeric_limits<int>::max() || den < (long long)numeric_limits<int>::min())
        {
            throw overflow_error("overflow occurred during addition");
        }

        Fraction result((int)num, (int)den);
        result.reduce();
        return result;
    }

Fraction operator*(const Fraction& num1, const Fraction& num2) {
    if (num1.getNumerator() == 0 || num2.getNumerator() == 0) {
        return Fraction(0);
    }

    int min_val = numeric_limits<int>::min();

    if (num1.getNumerator() == min_val || num2.getNumerator() == min_val) {
            throw overflow_error("overflow occurred during multiplication");
    }

    int max_val = numeric_limits<int>::max();

    if (num1.getNumerator() > max_val / num2.getDenominator() || num2.getNumerator() > max_val / num1.getDenominator()) {
        throw overflow_error("overflow occurred during multiplication");
    }

    int num = num1.getNumerator() * num2.getNumerator();
    int den = num1.getDenominator() * num2.getDenominator();

    Fraction result(num, den);
    result.reduce();
    return result;
}
    
    Fraction operator/(const Fraction &num1, const Fraction &num2){
    
    if (num2.getNumerator() == 0)
    {
        throw runtime_error("ilegal divison by 0");
    }

    long long num = (long long) num1.getNumerator() * (long long) num2.getDenominator(); 
    long long den = (long long) num1.getDenominator() * (long long) num2.getNumerator();
    
    int min_val = numeric_limits<int>::min();
    int max_val = numeric_limits<int>::max();

    if (num > max_val || num < min_val) {
        throw overflow_error("Overflow occurred during division");
    }
    if (den > max_val || den < min_val) {
        throw overflow_error("Overflow occurred during division");
    }

    Fraction result((int) num, (int) den);
    return result;

    }   


    bool operator==(const Fraction& num1, const Fraction& num2){
        // return (num1.numerator == num2.numerator) && (num1.denominator ==num2.denominator);

        // first multiplies the numerator of each fraction by 1000 and divides by the denominator, 
        // keeping only the three digits after the decimal point.
        int digits1 = (int)(num1.getNumerator() * 1000 / num1.getDenominator()) % 1000;
        int digits2 = (int)(num2.getNumerator() * 1000 / num2.getDenominator()) % 1000;
        return digits1 == digits2;
    }

    // bool operator!=(const Fraction& num1, const Fraction& num2){
    //     return !(num1 == num2);
    // }

    bool operator!=(const Fraction& num1, const Fraction& num2) {
        
        int digits1 = num1.getNumerator() * num2.getDenominator();
        int digits2 = num2.getNumerator() * num1.getDenominator();
        return digits1 != digits2;
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