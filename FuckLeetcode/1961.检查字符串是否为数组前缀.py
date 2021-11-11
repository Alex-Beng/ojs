#
# @lc app=leetcode.cn id=1961 lang=python3
#
# [1961] 检查字符串是否为数组前缀
#

# @lc code=start
class Solution:
    def isPrefixString(self, s: str, words: [str]) -> bool:
        return s in [''.join(words[:i]) for i in range(1, len(words)+1)]
# @lc code=end

