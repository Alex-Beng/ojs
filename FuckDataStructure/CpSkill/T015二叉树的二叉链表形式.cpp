/*
A(B(#,D),C(E(#,F),#))
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    string in_str;
    string ans_str = "";
    cin>>in_str;
    for (int i=0; i<in_str.length(); i++) {
        if (in_str[i] != '('
        && in_str[i] != ')'
        && in_str[i] != ',') {
            ans_str += in_str[i];
        }
    }
    cout<<ans_str<<endl;
    return 0;
}
