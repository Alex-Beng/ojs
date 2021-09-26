/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        while (b!=0) {
            auto t = a^b;
            b = (unsigned int)(a&b)<<1;
            a = t;
        }
        return a;
    }
};
// @lc code=end

