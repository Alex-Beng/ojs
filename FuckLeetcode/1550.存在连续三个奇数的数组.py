#
# @lc app=leetcode.cn id=1550 lang=python3
#
# [1550] 存在连续三个奇数的数组
#

# @lc code=start
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        arr = [i&1 for i in arr]
        n = len(arr)
        val = [sum(arr[i:i+3]) for i in range(n-2)]
        # print(val)
        return max(val+[0])==3
# @lc code=end

