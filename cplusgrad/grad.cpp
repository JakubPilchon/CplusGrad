#include <iostream>
#include "grad.h"

using namespace std;

Node::Node(float input) {
  value = input;
  dif = 1;
}

void Node::print() {
  cout << "<value = " << value << " dif = " << dif << ">" << endl;
}

Node Node::operator+(Node &a) {
  a.dif = 1; dif = 1;
  Node c(a.value + value);
  return c;
}

Node Node::operator-(Node &a) {
  a.dif = 1; dif = 1;
  Node c(a.value - value);
  return c;
}

Node Node::operator*(Node &a) {
  a.dif = value; dif = a.value;
  Node c(a.value - value);
  return c;
}

Node Node::operator/(Node &a) {
  a.dif = -1; dif = 1;
  Node c(a.value - value);
  return c;
}
void operations::backward_test(Node *self, Node *other) {
        self->dif = other->value; 
        other->dif = self->value; 
    }