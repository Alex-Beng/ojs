#
# @lc app=leetcode.cn id=90 lang=python3
#
# [90] 子集 II
#

# @lc code=start
class Solution:
    def subsetsWithDup(self, nums: [int]) -> [[int]]:
        n = len(nums)
        ans = set()
        for i in range(0, 1<<n):
            t = tuple(sorted([nums[j] for j in range(n) if i & 1<<j]))
            ans.add(t)
        # print(ans)
        return [list(i) for i in ans]
            # print(t)
            # for j in range(0, n):
            #     if i & 1<<j:


# @lc code=end

s = Solution()
s.subsetsWithDup(
 [1,2,2]
)