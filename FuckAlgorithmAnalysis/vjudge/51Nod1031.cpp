#include <iostream>
using namespace std;

const int mod = 1000000000+7;
int dp[2333];

int main(int argc, char const *argv[]) {
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<=1000; i++) {
        dp[i] = ((dp[i-1])%mod + (dp[i-2])%mod)%mod;
    }
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
    return 0;
}