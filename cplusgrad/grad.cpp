#include <iostream>
#include "grad.h"

using namespace std;

Node::Node(float input) {
    value = input;
    dif = 10;
    
}

Node operations::add_nodes(Node &a, Node &b) {
    a.dif = 1; b.dif = 1;
    Node c(a.value + b.value);
    return c;
}
Node operations::dec_nodes(Node &a, Node &b) {
    a.dif = 1; b.dif = 1;
    Node c(a.value - b.value);
    return c;
}
Node operations::mul_nodes(Node &a, Node &b) {
    a.dif = b.value; b.dif = a.value;
    Node c(a.value - b.value);
    return c;
}
Node operations::dec_nodes(Node &a, Node &b) {
    a.dif = 1; b.dif = 1;
    Node c(a.value - b.value);
    return c;
}