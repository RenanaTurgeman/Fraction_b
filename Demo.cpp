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

    // Fraction t(9,7) , g(2,7);
    //     cout <<"t= "<< t << endl;
    //     cout <<"g= "<< g << endl;

}
