#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    char str[233];
    char stack[233];
    int stack_len = 0;
    cin>>str;
    for (int i=0; i<strlen(str); i++) {
        if (str[i] == '[' || str[i] == '(') {
            stack[stack_len++] = str[i];
        }
        else if (str[i] == ']' && stack[stack_len-1] == '[') {
            stack_len--;

        }
        else if (str[i] == ')' && stack[stack_len-1] == '(') {
            stack_len--;

        }
        else {
            stack[stack_len++] = str[i];
        }
    }
    if (stack_len==0) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    return 0;
}
