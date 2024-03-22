#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>
using namespace std;

class Complex
{
public:
    Complex();
    Complex(string name, int re, int im);
    Complex(string formatted_complex);

    string getName();
    int getRe();
    int getIm();

    void print();

    Complex* add(string str, Complex* other);
    Complex* sub(string str, Complex* other);

    ~Complex();
private:
    string name;
    int re, im;

    string findName(string formatted_complex, int& pos);
    int readNumber(string formatted_complex, int& pos);
};

#endif // COMPLEX_H
