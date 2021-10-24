#
# @lc app=leetcode.cn id=2032 lang=python3
#
# [2032] 至少在两个数组中出现的值
#

# @lc code=start
class Solution:
    def twoOutOfThree(self, nums1: [int], nums2: [int], nums3: [int]) -> [int]:
        def num2vec(nums: [int]) -> tuple:
            vec = [0]*101
            for n in nums:
                vec[n] += 1
            return tuple(vec)
        n1vec = num2vec(nums1)
        n2vec = num2vec(nums2)
        n3vec = num2vec(nums3)

        ans = []
        for i in range(1, 101):
            if n1vec[i] and n2vec[i] or n1vec[i] and n3vec[i] \
                or n2vec[i] and n3vec[i]:
                ans.append(i)
        return ans
# @lc code=end

