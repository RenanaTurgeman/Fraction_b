#include "Fraction.hpp"
 using namespace std;

namespace ariel{
    Fraction::Fraction(){
        this->numerator=1;
        this->denominator =1;
    }
    
    Fraction::Fraction(int num , int den ) : numerator(num), denominator(den) {
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

//     float ariel::toFloat(const Fraction &a)
// {
//     float numerator_a = (float)a.getNumerator();
//     float denominator_a = (float)a.getDenominator();
//     float fraction_float = numerator_a / denominator_a;
//     return round(fraction_float * 1000) / 1000;
// }
}