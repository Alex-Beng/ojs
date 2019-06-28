#include <cstring>
#include <iostream>
using namespace std;

int Ope(int op1, int op2, char ope) {
    if (ope == '+') {
        return op1+op2;
    }
    else if (ope == '-') {
        return op1-op2;
    }
    else if (ope == '*') {
        return op1*op2;
    }
    else if (ope == '/') {
        return op1/op2;
    }
}

int main() {
    char str[23];
    int sk[23];
    int sk_tail = 0;
    int op1, op2;
    int ans = -233;
    cin>>str;
    if (strlen(str) == 1) {
        cout<<str<<endl;
        return 0;
    }
    for (int i=0; i<strlen(str); i++) {
        if (str[i] == '+'
        ||  str[i] == '-'
        ||  str[i] == '*'
        ||  str[i] == '/') {
            // if (ans == -233) {
            op1 = sk[--sk_tail];
            op2 = sk[--sk_tail];
            ans = Ope(op2, op1, str[i]);
            sk[sk_tail++] = ans;
            // }
            // else {
            //     op1 = sk[--sk_tail];
            //     // cout<<ans<<' '<<op1<<str[i]<<endl;
            //     ans = Ope(op1, ans, str[i]);
            // }
        }
        else {
            sk[sk_tail++] = str[i]-'0';
        }
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}