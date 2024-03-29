// Oscar Cisneros and Kevin Ortiz
// Project 4
// Problem 1: The Fibonacci Problem and the Golden Ratio
// Algorithm 1B: Fibonacci Problem - Golden Ratio
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
#include <iostream>
#include <cmath>
#include <optional>
#include <sstream>
#include <string>

using namespace std;

// function prototype
// Find the fibonacci number using the golden ratio, using Fp
// which represents the preciding terms of Fn. The ratio approximates
// 1.61803. The function will return the nth term of the sequence.
// The user will enter 'p' and 'n' to calculate Fn, where p is a positive
// integer and non-floating point number.
// @param int p - the precedings term of Fn
// @param int n - the nth term of the sequence
// @return double - the value of the nth term of the sequence
double fib_goldenratio_equation4(int p, int n);
// function prototype
// Find the fibonacci number using the golden ratio, using Fn
// to find fn+1. The ratio approximates 1.61803. The function will
// return the preceding term of the sequence.
// @param int n - the nth term of the sequence
// @return double - the value of the preceding term of the sequence
double fib_goldenratio_equation5(int n);

// converts the user input to an optional that will be used in place of the value
// if the user inputs anything other than an integer
/** https://stackoverflow.com/questions/70736444/validating-stdcin-in-c-as-float/70736592#70736592 **/
template <typename T>
auto string_to(const string &s) {
  // the desired type
  T value;
  // convert the string to a stream
  istringstream ss(s);
  // the value is injected into the stream and we test wether
  // removing whitespace yields an eof flag
  // if not the value was not an integer
  return ((ss >> value) and (ss >> ws).eof())
  // if value is a number and not a float return it
  ? value
  // otherwise return an empty optional of type int
  : optional<T> {};
}

// ensure that p is a valid integer
int validate_input_integer() {
  int n;
  do {
    cout << "Enter a positive integer value for p: ";
    string buffer;
    getline(cin, buffer);
    auto p = string_to<int>(buffer);
    // because p is an optional, if the conversion to integer was not successful
    // p will be a null pointer. we can also bounds check by dereferncing the pointer.
    if (!p || (*p < 0)) {
      // continue to prompt users until input is valid
      cout << "Invalid input. Please enter a positive integer value for p." << endl;
    } else {
      // assign to return (stack) variable and return
      n = *p;
      return n;
    }
  } while (true);
}

// main driver
int main()
{
    int p = validate_input_integer(), n = 0;
    double fn, fnext = 0;    
    // prompt user for input 'n'
    cout << "Enter the nth term of the sequence: ";
    cin >> n;
    cout << endl;

    // print the nth term of the sequence using fp for fib_goldenratio_equation4
    cout << "printing fn from fp from equation (4):" << endl;
    cout << fib_goldenratio_equation4(p, n) << endl << endl;
    cout << "printing fn from equation (5):" << endl;
    cout << fib_goldenratio_equation5(n) << endl << endl;

    // print the first 20 terms of the sequence using fib_goldenratio_equation4
    p = 0;
    cout << "Printing the first 20 terms of the sequence using fib_goldenratio_equation4:" << endl;
    for (int n = 1; n <= 20; n++) {
        double f = fib_goldenratio_equation4(p, n);
        cout << f << " ";
        p = n;
    }
    cout << endl << endl;

    // print the first 20 terms of the sequence using fib_goldenratio_equation5
    cout << "Printing the first 20 terms of the sequence using fib_goldenratio_equation5:" << endl;
    for (int n = 1; n <= 20; n++) {
        double f = fib_goldenratio_equation5(n);
        cout << f << " ";
    }
    cout << endl << endl;
    
    // Compare outputs from equations (4) and (5)
    p = 0;
    cout << "Comparison of outputs from equations (4) and (5):" << endl;
    for (int n = 1; n <= 20; n++) {
        double f4 = fib_goldenratio_equation4(p, n);
        double f5 = fib_goldenratio_equation5(n);
        cout << "Term: " << n << " Equation 4: " << f4 << " | Equation 5: " << f5 << endl;
        p = n;
    }
    cout << endl;

    // Check maxim using F3/F2 and F30/F29 from equation (5)
    double f3 = fib_goldenratio_equation5(3);
    double f2 = fib_goldenratio_equation5(2);
    double f30 = fib_goldenratio_equation5(30);
    double f29 = fib_goldenratio_equation5(29);
    cout << "Checking maxim using F3/F2 and F30/F29 from equation (5):" << endl;
    cout << "F3/F2 = " << f3 / f2 << endl;
    cout << "F30/F29 = " << f30 / f29 << endl << endl;
    return 0;
}
// function definition
double fib_goldenratio_equation4(int p, int n) {
    // variable declaration
    double fp = 0;
    double fn = 0;
    // find Fp via formula Fn = [( 1 + sqrt(5) )^n - ( 1 - sqrt(5) )^n ] / ( 2^n * sqrt(5) )
    fp = ( pow((1 + sqrt(5)), p) - pow((1 - sqrt(5)), p)) / (pow(2, p) * sqrt(5));
    // find Fn via formula Fn = Fp * (1.61803)^(n-p)
    fn = round(fp * pow(1.61803, (n - p)));
    return fn;
}
// function definition
double fib_goldenratio_equation5(int n) {
    // variable declaration
    double fn = 0;
    double fnext = 0;
    // find Fn via formula Fn = (1.61803)^n / sqrt(5)
    fn = ( pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n)) / (pow(2, n) * sqrt(5));
    fnext = round(fn * (1.61803));
    return fnext;
}
