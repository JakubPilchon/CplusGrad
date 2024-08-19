#include <iostream>

using namespace std;

class Node {
    public:
    float value, dif;
    Node(float);
};

namespace operations {
    Node add_nodes(Node &, Node &);
    Node dec_nodes(Node &, Node &);
    Node mul_nodes(Node &, Node &);
    Node div_nodes(Node &, Node &);
}
