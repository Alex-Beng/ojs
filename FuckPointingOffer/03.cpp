#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // naive way
    int findRepeatNumber(vector<int>& nums) {
        int ans;
        int n=nums.size();
        int bins[n];
        for (int i=0; i<n; i++) {
            bins[i] = 0;
        }
        for (int i=0; i<nums.size(); i++) {
            bins[nums[i]]++;
        }
        for (int i=0; i<n; i++) {
            if(bins[i] > 1) {
                ans = i;
            }
        }
        return ans;
    }

    // hash way
    int findRepeatNumber(vector<int>& nums) {
        std::unordered_map<int, int> num2times;
        for (auto& num : nums) {
            num2times[num]++;
        }
        for (auto& pr : num2times) {
            if (pr.second > 1) {
                return pr.first;
            }
        }
        return -1;
    }
};

