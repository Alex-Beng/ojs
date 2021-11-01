#
# @lc app=leetcode.cn id=718 lang=python3
#
# [718] 最长重复子数组
#

# @lc code=start
class Solution:
    def findLength(self, nums1: [int], nums2: [int]) -> int:
        n1 = len(nums1)
        n2 = len(nums2)
        dp = [[0]*(n2+1) for _ in range(n1+1)]

        for i in range(n1):
            for j in range(n2):
                if nums1[i]==nums2[j]:
                    dp[i][j] = dp[i-1][j-1]+1
        return max([max(r) for r in dp])
# @lc code=end

