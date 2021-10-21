#
# @lc app=leetcode.cn id=229 lang=python3
#
# [229] 求众数 II
#

# @lc code=start
class Solution:
    def majorityElement(self, nums: [int]) -> [int]:
        n_n = len(nums)

        n2times = dict()
        for n in nums:
            if n in n2times:
                n2times[n] += 1
            else:
                n2times[n] = 1
        ans = []
        for n in n2times:
            t = n2times[n]
            if t*3 > n_n:
                ans.append(n)
        return ans
# @lc code=end

