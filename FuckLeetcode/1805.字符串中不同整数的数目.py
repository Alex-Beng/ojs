#
# @lc app=leetcode.cn id=1805 lang=python3
#
# [1805] 字符串中不同整数的数目
#

# @lc code=start
import re
class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        return len(set([int(i) for i in re.findall(r"[0-9]+", word)]))
# @lc code=end