#include <iostream>
using namespace std;
int factorial_[10000];

int main() {
    factorial_[1] = 1;
    int n;
    int ans = 1;
    cin>>n;
    for (int i=2;i<=n;i++) {
        factorial_[i] = factorial_[i-1]*i;
        ans += factorial_[i];
    }
    cout<<ans<<endl;
    return 0;
}