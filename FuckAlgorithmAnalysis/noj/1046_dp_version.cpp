#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    while (cin>>n&&n) {
        int height[n];
        int dp[n];
        int ans = -1;
        for (int i=0; i<n; i++) {
            cin>>height[i];
            dp[i] = 1;
            for (int j=0; j<i; j++) {
                if (height[j] >= height[i]) {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
