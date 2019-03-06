#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int num[2333];
    int dp[2333];
    int n;
    int ans = -1;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>num[i];
    }
    dp[0] = num[0];
    for (int i=1; i<n; i++) {
        dp[i] = max(dp[i-1]+num[i],num[i]);
        if (dp[i] > ans) {
            ans = dp[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
