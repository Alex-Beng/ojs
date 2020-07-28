class Solution {
public:
    int ans[101];
    Solution() {
        ans[0] = 1;
        ans[1] = 1;
        for (int i=2; i<=100; i++) {
            ans[i] = ans[i-1]+ans[i-2];
            if (ans[i] > 1000000007) {
                ans[i] = ans[i] % 1000000007;
            }
        }
    }
    int numWays(int n) {
        return ans[n];
    }
};