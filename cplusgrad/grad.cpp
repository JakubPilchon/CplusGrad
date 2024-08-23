#include <iostream>
#include "grad.h"

using namespace std;

Node::Node(float input) {
  value = input;
  dif = 1;
}

Node::Node(float input, Node* list[2]) {
  value = input;
  dif = 1;
  parents[0] = list[0];
  parents[1] = list[1];
}

void Node::print() {
  cout << "<value = " << value << " dif = " << dif << ">" << endl;
}


Node Node::operator+(Node &a) {
  a.dif = 1; dif = 1;
  Node* arr[2] = {this, &a};
  Node c(a.value + value, arr);
  return c;
}

Node Node::operator-(Node &a) {
  a.dif = 1; dif = 1;
  Node* arr[2] = {this, &a};
  Node c(a.value - value, arr);
  return c;
}

Node Node::operator*(Node &a) {
  a.dif = value; dif = a.value;
  Node* arr[2] = {this, &a};
  Node c(a.value * value, arr);
  return c;
}

Node Node::operator/(Node &a) {
  a.dif = -1; dif = 1;
  Node* arr[2] = {this, &a};
  Node c(a.value / value, arr);
  return c;
}

Node Node::square() {
Node* arr[2] = {this, nullptr};
Node c(value * value, arr);
return c;
}


void operations::backward_test(Node *self, Node *other) {
        self->dif = other->value; 
        other->dif = self->value; 
    }