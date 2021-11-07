#
# @lc app=leetcode.cn id=1207 lang=python3
#
# [1207] 独一无二的出现次数
#

# @lc code=start
class Solution:
    def uniqueOccurrences(self, arr: [int]) -> bool:
        n2times = dict()
        for n in arr:
            if n in n2times:
                n2times[n] += 1
            else:
                n2times[n] = 1
        arr = n2times.values()
        n2times = dict()
        for n in arr:
            if n in n2times:
                n2times[n] += 1
            else:
                n2times[n] = 1
        return max(n2times.values()) <= 1
# @lc code=end