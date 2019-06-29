#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* l_child;
    Node* r_child;
    Node() {
        l_child = NULL;
        r_child = NULL;
    }
};

void output(Node* root) {
    if (root) {
        cout<<root->data<<endl;
        output(root->l_child);
        output(root->r_child);
    }
}


int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int node_info[n][3];
    Node* nodes_ptr[n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin>>node_info[i][j];
        }
        nodes_ptr[i] = new Node;
        nodes_ptr[i]->data = node_info[i][0];
    }
    for (int i=0; i<n; i++) {
        if(node_info[i][1] != 0) {
            nodes_ptr[i]->l_child = nodes_ptr[node_info[i][1]];
        }
        if(node_info[i][2] != 0) {
            nodes_ptr[i]->r_child = nodes_ptr[node_info[i][2]];
        }
    }
    output(nodes_ptr[0]);
    return 0;
}