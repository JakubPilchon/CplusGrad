#include <iostream>
#include <queue>
#include "grad.h"

using namespace std;

Node::Node(float input) {
  value = input;
}

Node::Node(float input, Node* list[2]) {
  value = input;
  parents[0] = list[0];
  parents[1] = list[1];
}

void Node::print() {
  cout << "<value = " << value << " dif = " << dif << ">" << endl;
}

Node Node::operator+(Node &a) {
  Node* arr[2] = {this, &a};
  Node c(a.value + value, arr);
  c.backwardPtr = Node::back_add;
  return c;
}

Node Node::operator-(Node &a) {
  a.dif = 1; dif = 1;
  Node* arr[2] = {this, &a};
  Node c(a.value - value, arr);
  return c;
}

Node Node::operator*(Node &a) {
  Node* arr[2] = {this, &a};
  Node c(a.value * value, arr);
  c.backwardPtr = Node::back_mul;
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
c.backwardPtr = Node::back_sqr;
return c;
}

void Node::back_default (){} // does nothing

void Node::back_add () {
  parents[0]->dif = dif;
  parents[1]->dif = dif;
}
void Node::back_mul () {
parents[0]->dif = parents[1]->value * dif;
parents[1]->dif = parents[0]->value * dif;
}
void Node::back_sqr () {
  parents[0]->dif = 2 * dif;
}

void Node::iterate_through () {
  queue<Node*> q; // main queue
  q.push(this);
  cout << "A";
  (this->*backwardPtr)();
  cout << "B" << endl;

  while (!q.empty()){
      Node* working_pointer = q.front();
      q.pop();
      for (int i=0; i<2; i++) {
        Node* x = working_pointer->parents[i];
        if (x != nullptr) {
          cout << "Node with value " << x->value << " is a child of Node with value " << working_pointer->value << endl;
          q.push(x);
          if (x != nullptr && x->backwardPtr != nullptr) {(x->*backwardPtr)();}else{cout << "Segfault!" << endl;}
          x->print();
        } else {
          cout << "null pointer detected!!" << endl;
        }
    }
}
}

void operations::backward_test(Node *self, Node *other) {
        self->dif = other->value; 
        other->dif = self->value; 
    }