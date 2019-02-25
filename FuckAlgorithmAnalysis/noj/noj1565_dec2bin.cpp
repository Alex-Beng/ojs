#include <iostream>
using namespace std;
void dec2bin(int n) {
    if (n<2) {
        if (n==1)
            cout<<n<<endl;
        else 
            ;
    }
    else {
        int t = n%2;
        cout<<t<<endl;
        dec2bin(n/2);
    }
}
int main(){
    int n;
    cin>>n;
    dec2bin(n);
    return 0;
}