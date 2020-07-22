#include <iostream>
using namespace std;

void showHex(int x) {
    if (x>=0 && x<=9) {
        cout<<x;
    }
    else {
        cout<<(char)(x-10 + 'A');
    }
}

void dec2hex(int x) {
    if (x==0) {
        return ;
    }
    int ans = x%16;
    dec2hex(x/16);
    showHex(ans);
}

int main(int argc, char const *argv[]) {
    int n;
    char t;
    
    for (int i=0; i<3; i++) {
        cin>>n;
        cin>>t;
        if (n)
            dec2hex(n);
        else 
            cout<<n;
        cout<<'.';
    }
    cin>>n;
    if (n)
        dec2hex(n);
    else 
        cout<<n;

    return 0;
}