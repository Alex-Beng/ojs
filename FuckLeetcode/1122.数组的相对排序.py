#
# @lc app=leetcode.cn id=1122 lang=python3
#
# [1122] 数组的相对排序
#

# @lc code=start
class Solution:
    def relativeSortArray(self, arr1: [int], arr2: [int]) -> [int]:
        a2max = max(arr2)
        num2idx = dict()
        for i,n in enumerate(arr2):
            num2idx[n] = i
        def n2key(n):
            if n in num2idx:
                return num2idx[n]
            else:
                return a2max+n
        return sorted(arr1, key=n2key)
# @lc code=end

