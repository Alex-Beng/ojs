#
# @lc app=leetcode.cn id=434 lang=python3
#
# [434] 字符串中的单词数
#

# @lc code=start
class Solution:
    def countSegments(self, s: str) -> int:
        return len(
           [t for t in s.split(' ') if t!='']
        ) 
# @lc code=end