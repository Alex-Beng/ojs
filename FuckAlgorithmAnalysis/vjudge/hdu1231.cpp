#include <cstdio>

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    int nums[23333];
    int dp[23333];
    int b_idx[23333];

    int ans, ans_idx;
    while (1) {
        scanf("%d", &n);
        if (!n) break;

        ans = -100000;
        ans_idx = -1;
        for (int i=0; i<n; i++) {
            // cin>>nums[i];
            scanf("%d", nums+i);
            if (i==0) {
                dp[i] = nums[i];
                ans_idx = i;
            }
            else {
                if (nums[i] > dp[i-1]+nums[i]) {
                    dp[i] = nums[i];
                    b_idx[i] = i;
                }
                else {
                    dp[i] = dp[i-1]+nums[i];
                    b_idx[i] = b_idx[i-1];
                }
            }
            if (dp[i] > ans) {
                ans = dp[i];
                ans_idx = i;
            }
        }
        if (ans<0) {
            printf("%d %d %d\n", 0, nums[0], nums[n-1]);
        }
        else {
            printf("%d %d %d\n", ans, nums[b_idx[ans_idx]], nums[ans_idx]);
        }
    }
    
    return 0;
}