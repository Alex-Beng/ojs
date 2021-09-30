/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    std::map<int, std::string> n2s = {
        {0,"0"},
        {1,"1"},
        {2,"2"},
        {3,"3"},
        {4,"4"},
        {5,"5"},
        {6,"6"},
        {7,"7"},
        {8,"8"},
        {9,"9"},
        {10,"a"},
        {11,"b"},
        {12,"c"},
        {13,"d"},
        {14,"e"},
        {15,"f"},
    };
    std::string toHex(int num) {
        if (!num) return "0";
        unsigned int unum = (unsigned int)num;
        std::string ans = "";
        while (unum != 0) {
            auto t = (unsigned int)unum & 0xf;
            unum >>= 4;
            ans = n2s[t] + ans;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    cout<<s.toHex(-1);
    return 0;
}
