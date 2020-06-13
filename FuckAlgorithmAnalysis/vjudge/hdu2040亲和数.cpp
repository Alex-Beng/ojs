#include <iostream>
using namespace std;

int SumOfDivisor(int n) {
    int ans = 0;
    for (int i=1; i<n; i++) {
        if (n%i == 0) {
            ans += i;
        }
    }
    return ans;
}


int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int n1, n2;
        cin>>n1>>n2;
        // cout<<SumOfDivisor(n1)<<' '<<SumOfDivisor(n2)<<endl;
        if (SumOfDivisor(n1) == n2 && SumOfDivisor(n2) == n1) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}