#include <iostream>
#include "grad.h"
#include <queue>
using namespace std;

void iterate(Node &a) {
// BFS through Nodes graph
  queue<Node*> q; // main queue
  q.push(&a);

    while (!q.empty()){
      Node* working_pointer = q.front();
      q.pop();
      for (int i=0; i<2; i++) {
        Node* x = working_pointer->parents[i];
        if (x != nullptr) {
          q.push(x);
          cout << "Node with value " << x->value << " is a child of Node with value " << working_pointer->value << endl;
        } else {
          cout << "null pointer detected!!" << endl;
        }
    }
}}



int main() {
    //Node a(1.5), b(0.5), c(3.0);
    //Node d = a + b; // d = 2
    //Node e = d * c; // e = 6
    //Node f = e.square();
    //f.iterate_through();
    Node x(4);
    Node a(3);
    Node c = a * x;
    Node b = c.square();
    //b.iterate_through();
    iterate(b);
    a.print();
    return 0;
}