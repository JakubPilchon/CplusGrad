#include <iostream>
#include "grad.h"

using namespace std;

int main() {
    Node a(1.5), b(0.5);
    Node c = operations::add_nodes(a, b);
    cout << c.value << " value" << endl;
    cout << a.dif << " a dif";
    //cin >> "click to end"
    cin.get();
}