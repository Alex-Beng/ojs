#include <algorithm>
#include <iostream>
using namespace std;

int n;
int char_to_weight[256];
int weight_to_char[101];

struct TreeNode {
    char data;
    TreeNode* l_child;
    TreeNode* r_child;
    TreeNode* parent;
    TreeNode(): l_child(NULL), r_child(NULL), parent(NULL) {}
};


bool for_sort(char& a, char& b) {
    if (char_to_weight[a] > char_to_weight[b]) {
        return false;
    }
    else {
        return true;
    }
}

int main(int argc, char const *argv[]) {
    cin>>n;
    char charaters[n];
    for (int i=0; i<n; i++) {
        cin>>charaters[i];
    }
    for (int i=0; i<n; i++) {
        cin>>char_to_weight[charaters[i]];
        weight_to_char[char_to_weight[charaters[i]]] = charaters[i];
    }
    sort(charaters, charaters+n, for_sort);
    char encoded_str[233];
    cin>>encoded_str;


    return 0;
}
