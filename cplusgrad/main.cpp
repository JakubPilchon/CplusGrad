#include <iostream>
#include "grad.h"

using namespace std;

int main() {
    Node a(1.5), b(0.5), c(2.0);
    Node d = (a+b) + c;
    d.print();
    //cout << a.dif << " a dif" << endl << b.dif << " b dif";
}