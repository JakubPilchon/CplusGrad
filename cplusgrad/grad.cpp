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
  c.backwardPtr = &Node::back_add;
  return c;
}
Node Node::operator+(float a) {
  Node new_node = Node(a);
  Node c = Node::operator+(new_node);
  return c;
}

Node Node::operator-(Node &a) {
  Node* arr[2] = {this, &a};
  Node c(value - a.value, arr);
  c.backwardPtr = &Node::back_sub;
  return c;
}
Node Node::operator-(float a) {
  Node new_node = Node(a);
  Node c = Node::operator-(new_node);
  return c;
}

Node Node::operator*(Node &a) {
  Node* arr[2] = {this, &a};
  Node c(a.value * value, arr);
  c.backwardPtr = &Node::back_mul;
  return c;
}
Node Node::operator*(float a) {
  Node new_node = Node(a);
  Node c = Node::operator*(new_node);
  return c;
}

Node Node::operator/(Node &a) {
  Node* arr[2] = {this, &a};
  Node c(a.value / value, arr);
  c.backwardPtr = &Node::back_div;
  return c;
}
Node Node::operator/(float a) {
  Node new_node = Node(a);
  Node c = Node::operator/(new_node);
  return c;
}


Node Node::square() {
  Node* arr[2] = {this, nullptr};
  Node c(value * value, arr);
  c.backwardPtr = &Node::back_sqr;
  return c;
}

void Node::back_default (){} // does nothing

void Node::back_add () {
  parents[0]->dif = dif;
  parents[1]->dif = dif;
}

void Node::back_sub () {
  parents[0]->dif = dif;
  parents[1]->dif = -dif;
}

void Node::back_mul () {
  parents[0]->dif = parents[1]->value * dif;
  parents[1]->dif = parents[0]->value * dif;
}

void Node::back_div () {
  parents[0]->dif = (1/parents[1]->value) * dif;
  parents[1]->dif = -parents[0]->value/(parents[1]->value * parents[1] ->value) * dif;
}

void Node::back_sqr () {
  parents[0]->dif = 2 * dif;
}

void Node::iterate_through () {
  queue<Node*> q; // main queue
  q.push(this);

  while (!q.empty()){
    Node* working_pointer = q.front();
    q.pop();
    (working_pointer->*(working_pointer->backwardPtr))();
    for (int i=0; i<2; i++) {
      Node* x = working_pointer->parents[i];
      if (x != nullptr) {
        cout << "Node with value " << x->value << " and this derivative: " << x->dif << " is a child of Node with value " << working_pointer->value << endl;
        q.push(x);
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