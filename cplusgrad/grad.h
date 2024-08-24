#include <iostream>

using namespace std;


class Node {
  public:
    float value; // variable for value
    float dif = 1.; // holding varible of derivative
    

    // methods:
    Node(float); // constructor overload designedc for user
    void print(); // prints basic info about node, for debugging
    void iterate_through();

    // Operations:
    Node operator+(Node &);
    Node operator-(Node &);
    Node operator*(Node &);
    Node operator/(Node &);
    Node square();

    //backward_operations
    void back_default ();
    void back_add ();
    void back_mul ();
    void back_sqr ();

    void (Node::*backwardPtr)() = Node::back_default; // function pointer for backward operation

    //private:
    Node* parents[2] = {nullptr, nullptr};
    private:
    Node(float, Node*[2]); // second constructor, to be used to create a graph
    
};

namespace operations {
    void backward_test(Node *self, Node *other);
};