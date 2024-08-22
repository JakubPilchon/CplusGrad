#include <iostream>

using namespace std;


class Node {
  public:
    float value, dif;
    void  (*backward)(Node *self, Node *other);

    // methods:
    Node(float);
    void print();
    Node operator+(Node &);
    Node operator-(Node &);
    Node operator*(Node &);
    Node operator/(Node &);
    //friend void operations::backward_test(Node*, Node*);

    //private:
    Node* parents[2] = {nullptr, nullptr};
    private:
    void set_parents(Node*, Node*);
    
};

namespace operations {
    void backward_test(Node *self, Node *other);
};