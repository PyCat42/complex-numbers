#include "Complex.h"
#include <cmath>
#include <iostream>
using namespace std;

Complex::Complex()
{
    this->name = "z";
    this->re = 0;
    this->im = 0;
}

Complex::Complex(string name, int re, int im)
{
    this->name = name;
    this->re = re;
    this->im = im;
}

string Complex::findName(string formatted_complex, int& pos)
{
    string name = "";
    while(formatted_complex[pos] != '=')
    {
        name += formatted_complex[pos];
        pos++;
    }
    return name;
}

int Complex::readNumber(string formatted_complex, int& pos)
{
    int read = 0;
    for(pos; pos < formatted_complex.length(); pos++)
    {
        if(formatted_complex[pos] >= '0' && formatted_complex[pos] <= '9')
        {
            read = read * 10 + (formatted_complex[pos] - '0');
        }
        else break;
    }
    return read;
}

Complex::Complex(string formatted_complex) //from given string to Complex
{
    int pos = 0;
    this->name = findName(formatted_complex, pos);

    pos++;

    int first_sign = 1;
    int sign_im = 1;

    if(formatted_complex[pos] == '-')
    {
        first_sign *= -1;
        pos++;
    }

    int num = readNumber(formatted_complex, pos);

    int re, im;
    bool readIm = false;

    if(formatted_complex[pos] == '+') //load real then + => im is positive
    {
        re = num * first_sign;
        readIm = true;
    }

    else if(formatted_complex[pos] == '-') //load real then - => im is negative
    {
        sign_im *= -1;
        re = num * first_sign;
        readIm = true;
    }

    else if(formatted_complex[pos] == 'i')//found i => loaded im not re
    {
        re = 0;
        im = (num == 0) ? 1* first_sign : num * first_sign;
    }

    else if(pos == formatted_complex.length()) //end of string => only re no im
    {
        re = num * first_sign;
        im = 0;
    }

    else
    {
        re = 0;
        im = 0;
    }

    pos++;

    if(readIm)
    {
        int im_num = readNumber(formatted_complex, pos);
        im = (im_num == 0) ? 1 * sign_im : im_num * sign_im;
    }

    this->im = im;
    this->re = re;
}

string Complex::getName()
{
    return this->name;
}

int Complex::getRe()
{
    return this->re;
}

int Complex::getIm()
{
    return this->im;
}

void Complex::print()
{
    string re_str, im_str, sign;

    sign = (this->im > 0) ? "+" : "";

    if(this->re == 0)
    {
        sign = "";
        re_str = "";
    }
    else
    {
        re_str = to_string(this->re);
    }


    if(this->im == 0)
    {
        im_str = "";
    }
    else if(this->im == 1)
    {
        im_str = "i";
    }
    else
    {
        im_str = to_string(this->im) + "i";
    }

    cout << this->name << "=" << re_str << sign << im_str << endl;
}

Complex* Complex::add(string str, Complex* other)
{
    int res_re = this->re + other->re;
    int res_im = this->im + other->im;
    Complex* result = new Complex(str, res_re, res_im);
    return result;
}

Complex* Complex::sub(string str, Complex* other)
{
    int res_re = this->re - other->re;
    int res_im = this->im - other->im;
    Complex* result = new Complex(str, res_re, res_im);
    return result;
}

Complex::~Complex()
{
    //dtor
}
