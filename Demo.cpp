/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(5,3), b(14,21);
    cout << "a: " << a << " b: " << b << endl;
    cout << "a+b= " << a+b << endl; 
    cout << "a-b= " << a-b << endl; 
    cout << "a/b= " << a/b << endl; 
    cout << "a*b= " << a*b << endl; 
    cout << "2.3*b= " << 2.3*b << endl; 
    cout << "a+2.421= " << a+2.421 << endl; 
    Fraction c = a+b-1; // =4/3
    cout <<"c= "<< c << endl;
    cout <<"c++="<< c++ << endl;
    cout <<"c= "<< c << endl;
    cout << --c << endl;

    cout <<"c= "<< c << endl;
    cout <<"b= "<< b << endl;
    cout <<"a= "<< a << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;
    cout << 5.321 - Fraction{2, 3} << endl;
/*
--------------------MY OWN DEMO--------------------------------------
*/
     // Create two fractions
        Fraction f1(1, 2);
        Fraction f2(3, 4);

        // Print the fractions
        cout << "f1 = " << f1 << endl;
        cout << "f2 = " << f2 << endl;

        // Test the arithmetic operators
        Fraction f3 = f1 + f2;
        Fraction f4 = f1 - f2;
        Fraction f5 = f1 * f2;
        Fraction f6 = f1 / f2;

        // Print the results of the arithmetic operations
        cout << "f1 + f2 = " << f3 << endl;
        cout << "f1 - f2 = " << f4 << endl;
        cout << "f1 * f2 = " << f5 << endl;
        cout << "f1 / f2 = " << f6 << endl;

        // Test the comparison operators
        bool b1 = f1 == f2;
        bool b2 = f1 != f2;
        bool b3 = f1 < f2;
        bool b4 = f1 > f2;
        bool b5 = f1 <= f2;
        bool b6 = f1 >= f2;

        // Print the results of the comparison operations
        cout << "f1 == f2: " << boolalpha << b1 << endl;
        cout << "f1 != f2: " << boolalpha << b2 << endl;
        cout << "f1 < f2: " << boolalpha << b3 << endl;
        cout << "f1 > f2: " << boolalpha << b4 << endl;
        cout << "f1 <= f2: " << boolalpha << b5 << endl;
        cout << "f1 >= f2: " << boolalpha << b6 << endl;

}
