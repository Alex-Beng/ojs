#
# @lc app=leetcode.cn id=645 lang=python3
#
# [645] 错误的集合
#

# @lc code=start
class Solution:
    def findErrorNums(self, nums: [int]) -> [int]:
        N = len(nums)

        num2time = dict()
        for n in nums:
            if n in num2time:
                num2time[n] += 1
            else:
                num2time[n] = 1
        dup_num = 0
        
        for k in num2time:
            if num2time[k]==2:
                dup_num = k
        del_num = dup_num + (N*(1+N)//2) - sum(nums)
        return [dup_num, del_num]

# @lc code=end

