#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int nums[n];
    int dp[n];
    int ans = -100000;
    for (int i=0; i<n; i++) {
        cin>>nums[i];
        if (!i) {
            dp[i] = nums[i];
        }
        else {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
        
    }
    cout<<ans<<endl;;
    return 0;
}