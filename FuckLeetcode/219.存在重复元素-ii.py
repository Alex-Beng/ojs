#
# @lc app=leetcode.cn id=219 lang=python3
#
# [219] 存在重复元素 II
#

# @lc code=start
class Solution:
    def containsNearbyDuplicate(self, nums: [int], k: int) -> bool:
        n = len(nums)

        l = 0
        # r = 0
        r = min(k,n)
        eles = set()
        for i in range(l, min(k+1, n)):
            if nums[i] in eles:
                return True
            else:
                eles.add(nums[i])
        while l<n and r<n:
            eles.discard(nums[l])
            l += 1
            r += 1
            if r==n:
                return False
            if nums[r] in eles:
                return True
            else:
                eles.add(nums[r])
        return False
# @lc code=end

s = Solution()
r = s.containsNearbyDuplicate(
    [1,0,1,1],1
)
print(r)