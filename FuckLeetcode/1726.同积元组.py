#
# @lc app=leetcode.cn id=1726 lang=python3
#
# [1726] 同积元组
#

# @lc code=start
class Solution:
    def tupleSameProduct(self, nums: [int]) -> int:
        prod2tup = dict()
        n = len(nums)
        for i in range(n):
            for j in range(n):
                if i==j:
                    continue
                tp = nums[i]*nums[j]
                if tp in prod2tup:
                    prod2tup[tp].append((i,j))
                else:
                    prod2tup[tp] = [(i,j)]
        ans = 0
        for tp in prod2tup:
            pairs = prod2tup[tp]
            np = len(pairs)
            for i in range(np):
                for j in range(np):
                    if i==j or tuple(sorted(pairs[i]))==tuple(sorted(pairs[j])):
                        continue
                    ans += 1
        return ans

                
# @lc code=end

