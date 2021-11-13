#
# @lc app=leetcode.cn id=1796 lang=python3
#
# [1796] 字符串中第二大的数字
#

# @lc code=start
class Solution:
    def secondHighest(self, s: str) -> int:
        ns = [int(c) for c in s if ord('0')<=ord(c)<=ord('9')]
        ns = list(set(ns))
        ns.sort()
        return(ns[-2]) if len(ns)>=2 else -1
# @lc code=end