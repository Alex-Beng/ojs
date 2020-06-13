/**
14
-10 0 0 0 0 1 2 3 4 -5 -23 3 7 -21

10
-10 1 2 3 4 -5 -23 3 7 -21

4       
-4 -1 -9 -4

4       
-4 -1 -9 -4

 * */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int nums[n];
    int dp[n];
    bool dped[n];
    int ans = -10000000;
    int ans_beg;
    int ans_end;
    bool has_pos = false;
    bool has_zero = false;

    for (int i=0; i<n; i++) {
        cin>>nums[i];
        if (nums[i] > 0) {
            has_pos = true;
        }
        if (!nums[i]) {
            has_zero = true;
        }
        if (!i) {
            dp[i] = nums[i];
            dped[i] = false;
            ans = dp[i];
            ans_end = 0;
        }
        else {
            if (dp[i-1] >= 0) { // 如果加前面一个
                dp[i] = dp[i-1]+nums[i];
                dped[i] = true;
            }
            else { // 如 果 从 头 来 过
                dp[i] = nums[i];
                dped[i] = false;
            }
        }
        if (dp[i] > ans) {
            ans = dp[i];
            ans_end = i;
        }
        // cout<<dp[i]<<endl;
    } 

    for (ans_beg=ans_end; dped[ans_beg]; ans_beg--) ;
    if (!has_pos) {
        ans = 0;
        ans_beg = 0;
        ans_end = n-1;
        if (has_zero) {
            nums[ans_beg] = 0;
            nums[ans_end] = 0;
        }
    }
    cout<<ans<<' '<<nums[ans_beg]<<' '<<nums[ans_end]<<endl;
}