/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 II
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
#include <unordered_map>

class Solution {
public:

    std::unordered_map<string, int> sig = {
        {"1", 1},{"2", 1},{"3", 1},{"4", 1},{"5", 1},{"6", 1},{"7", 1},{"8", 1},{"9", 1},{"10", 1},{"11", 1},{"12", 1},{"13", 1},{"14", 1},{"15", 1},{"16", 1},{"17", 1},{"18", 1},{"19", 1},{"20", 1},{"21", 1},{"22", 1},{"23", 1},{"24", 1},{"25", 1},{"26", 1},
    };
    std::unordered_map<char, int> fir2num = {
        {'0', 0},{'1', 9},{'2', 6},{'3', 0},{'4', 0},{'5', 0},{'6', 0},{'7', 0},{'8', 0},{'9', 0}
    };
    std::unordered_map<char, int> sec2num = {
        {'0', 2},{'1', 2},{'2', 2},{'3', 2},{'4', 2},{'5', 2},{'6', 2},{'7', 1},{'8', 1},{'9', 1},
    };
    
    int s2candi(string s) {
        auto it = sig.find(s);
        if (it != sig.end()) {
            return it->second;
        }
        if (s.length()==1) {
            if (s[0] != '0')
                return 9;
            else
                return 0;
        }
        else if (s=="**") {
            return 15;
        }
        else if (s[0]=='*') {
            return sec2num[s[1]];
        }
        else if (s[1]=='*') {
            return fir2num[s[0]];
        }
        else {
            return 0;
        }
    }

    int numDecodings(string s) {
        auto n = s.length();
        long long* dp = new long long[n];
        for (auto i=0; i<n; i++) {
            dp[i] = 0;
        }
        dp[0] = s2candi(s.substr(0,1));
        if (n==1) {
            return dp[0];
        }
        dp[1] = dp[0]*s2candi(s.substr(1,1)) + s2candi(s.substr(0,2));
        for (auto i=2; i<n; i++) {
            dp[i] += dp[i-1]*s2candi(s.substr(i,1)) + dp[i-2]*s2candi(s.substr(i-1,2));
            dp[i] %= 1000000007;
        }
        return dp[n-1];
    }
};
// @lc code=end