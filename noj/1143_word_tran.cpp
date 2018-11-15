#include <stack>
#include <iostream>
using namespace std;

int length;
int treatements[23333];
char src_str[23333];


bool check_output() {
    stack<char> sk;
    char output_str[23333];
    for (int i=0; i<2*length; i++) {
        if (treatements[i] == 1) {
            sk.push()
        } 
    }
}

void show() { 
    for (int i=0; i<2*length; i++) {   
        if (treatements[i] == 1) {
            cout<<'i'<<' ';
        }
        else {
            cout<<'o'<<' ';
        }
    }
    return;
}

void dfs(int layer) {
    if (layer == 2*length) {
        if (check_output()) {
            show();
        }
    }
    else {
        treatements[layer] = 1;
        dfs(layer+1);
        treatements[layer] = 0;
        dfs(layer=1);
    }
}


int main(int argc, char const *argv[]) {
    
    return 0;
}
