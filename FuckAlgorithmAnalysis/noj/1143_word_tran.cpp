#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

int length;
int treatements[23333];
char src_str[23333];
char target_str[23333];
int i_num = 0;
int o_num = 0;

bool check_output() {
    if (i_num != o_num) {
        return false;
    }
    stack<char> sk;
    int src_index = 0;
    int out_index = 0;
    char output_str[23333];
    for (int i=0; i<2*length; i++) {
        if (treatements[i] == 1) {
            sk.push(src_str[src_index]);
            src_index++;
        } 
        else if (treatements[i] == 0) {
            output_str[out_index] = sk.top();
            out_index++;
            sk.pop();
        }
    }
    for (int i=0; i<length; i++) {
        if (output_str[i] != target_str[i]) {
            return false;
        }
    }
    return true;
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
        if (i_num != length){
            treatements[layer] = 1;
            i_num++;
            dfs(layer+1);
            i_num--;
        }
        

        if (i_num >= o_num+1 && o_num != length) {
            o_num++;
            treatements[layer] = 0;
            dfs(layer+1);
        }
        
    }
}


int main(int argc, char const *argv[]) {
    while (cin>>src_str>> target_str) {
        i_num = 0;
        o_num = 0;
        length = strlen(src_str);
        dfs(0);
    }
    return 0;   
}
