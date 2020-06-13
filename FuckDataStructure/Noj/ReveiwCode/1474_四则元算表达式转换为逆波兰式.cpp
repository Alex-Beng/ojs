#include <string>
#include <cstring>
#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    char str[233];
    char ope_sk[233];
    int sk_len = 0;
    string ans = "";
    cin>>str;

    for (int i=0; i<strlen(str); i++) {
        if (str[i]=='(') {
            ope_sk[sk_len++] = str[i];
        }
        else if (str[i] == '+'
        ||       str[i] == '-'
        ||       str[i] == '*'
        ||       str[i] == '/') {
            ope_sk[sk_len++] = str[i];
        }
        else if (str[i] == ')') {
            while (sk_len != 0 && ope_sk[sk_len-1] != '(') {
                ans += ope_sk[--sk_len];
            }
            if (sk_len > 0) {
                sk_len--;
            }
        }
        else {
            ans += str[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
