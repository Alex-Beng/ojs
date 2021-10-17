#
# @lc app=leetcode.cn id=594 lang=python3
#
# [594] 最长和谐子序列
#

# @lc code=start
class Solution:
    def findLHS(self, nums: [int]) -> int:
        bins = dict()

        for n in nums:
            if n in bins:
                bins[n] += 1
            else:
                bins[n] = 1

        ans = 0
        for k in bins:
            if k+1 in bins:
                ans = max(ans, bins[k]+bins[k+1])
        return ans 
# @lc code=end
s = Solution()
s.findLHS(
    [1513929,1979802,15634022,35723058,69133069,25898167,59961393,89018456,28175011,56478042]
)