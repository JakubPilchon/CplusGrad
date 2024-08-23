#include <iostream>

using namespace std;


class Node {
  public:
    float value, dif;
    void  (*backward)(Node *self, Node *other);

    // methods:
    Node(float);
    void print();
    // Operations:
    Node operator+(Node &);
    Node operator-(Node &);
    Node operator*(Node &);
    Node operator/(Node &);
    Node square();

    //private:
    Node* parents[2] = {nullptr, nullptr};
    private:
    Node(float, Node*[2]); // second constructor
    
};

namespace operations {
    void backward_test(Node *self, Node *other);
};