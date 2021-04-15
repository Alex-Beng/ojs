#include <cstdio>

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    for (int ii=0; ii<t; ii++) {
        int n;
        cin>>n;
        int* nums = new int[n];
        int* dp = new int[n];
        int* idx = new int[n];
        
        int ans = -2333;//nums in [-1e3, 1e3]
        int ans_idx = -1;
        for (int i=0; i<n; i++) {
            cin>>nums[i];
            if (i==0) {
                idx[i] = 0;
                dp[i] = nums[i];
            }
            else {
                if (nums[i] > dp[i-1]+nums[i]) {
                    dp[i] = nums[i];
                    idx[i] = i;
                }
                else {
                    dp[i] = dp[i-1]+nums[i];
                    idx[i] = idx[i-1];
                }
            }
            if (dp[i] > ans) {
                ans = dp[i];
                ans_idx = i;
            }
        }

        printf("Case %d:\n%d %d %d\n\n", ii, ans, idx[ans_idx], ans_idx);
    }
    return 0;
}