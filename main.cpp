#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    string name = "z=10+16i";
    Complex z(name);
    cout << "String: " << name << endl;
    cout << "Real part: " << z.getRe() << endl;
    cout << "Imaginary part: " << z.getIm() << endl;

    cout << endl;

    Complex* c1 = new Complex("z", 3, 3);
    Complex* c2 = new Complex("x", 2, 2);
    Complex* c3 = new Complex();

    cout << "First number: " << endl;
    c1->print();
    cout << "Second number: " << endl;
    c2->print();

    cout << "Sum: ";
    c3 = c1->add("res", c2);
    c3->print();

    cout << "Sub: ";
    c3 = c1->sub("res", c2);
    c3->print();


    delete c1;
    delete c2;
    delete c3;

    return 0;
}
