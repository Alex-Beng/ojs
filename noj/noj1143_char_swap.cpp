#include <stack>
#include <iostream>
#include <string.h>
using namespace std;
int tree_depth;
std::stack<char> 

bool in_string(char a, char str[]) {
    for (int i =0; i < strlen(str); i++) {
        if (a == str[i]) {
            return true;
        }
    }
    return false;
}
bool equal(char str_1[],char  str_2[]) {
    for (int i=0; i<strlen(str_1); i++) {
        if (in_string(str_1[i],str_2)){
            ;
        }
        else {
            return false;
        }
    }
    return true;
}

void dfs(int depth) {
    if (depth>tree_depth) {

    }
    else {

    }
}

// str1 ---> str2
int main(int argc, char const *argv[])
{
    char str_1[10000];
    char str_2[10000];
    while (cin>>str_1>>str_2) {
        if (equal(str_1,str_2) && strlen(str_1) == strlen(str_2)) {
            tree_depth = 2*strlen(str_1);
            dfs()
        }
        else {
            cout<<"[]"<<endl;
        }
    }
    return 0;
}
