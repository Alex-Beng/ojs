#
# @lc app=leetcode.cn id=713 lang=python3
#
# [713] 乘积小于K的子数组
#

# @lc code=start
class Solution:
    def numSubarrayProductLessThanK(self, nums: [int], k: int) -> int:
        n = len(nums)
        b = 0
        tp = 1
        ans = 0
        for e in range(n):
            tp *= nums[e]
            while tp>=k and b<=e:
                tp /= nums[b]
                b += 1
            if b > e:
                continue
            else:
                ans += (e-b+1)
            
        return ans
# @lc code=end

s = Solution()
res = s.numSubarrayProductLessThanK(
    [10,5,2,6],100
)

print(res)