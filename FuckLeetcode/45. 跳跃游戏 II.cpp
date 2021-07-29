#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int* dp = new int[n];
        for (int i=0; i<n; i++) {
            // cout<<nums[i];
            dp[i] = 23333333;
        }
        // cout<<endl;

        dp[0] = 0;
        for (int i=0; i<n; i++) {
            int e_idx = min(n, i+nums[i]+1);
            for (int j=i; j<e_idx; j++) {
                dp[j] = min(dp[j], dp[i]+1);
            }
        }
        return dp[n-1];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    std::vector<int> ya = {2,3,1,1,4};
    
    cout<<s.jump(ya);
    return 0;
}
