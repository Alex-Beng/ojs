#
# @lc app=leetcode.cn id=1394 lang=python3
#
# [1394] 找出数组中的幸运数
#

# @lc code=start
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        n2times = dict()
        for n in arr:
            n2times[n] = n2times.get(n, 0)+1
        ans = [n for n in n2times if n==n2times[n]]
        if len(ans)==0:
            return -1
        else:
            return max(ans)
# @lc code=end