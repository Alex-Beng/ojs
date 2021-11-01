#
# @lc app=leetcode.cn id=454 lang=python3
#
# [454] 四数相加 II
#

# @lc code=start
class Solution:
    def fourSumCount(self, nums1: [int], nums2: [int], nums3: [int], nums4: [int]) -> int:
        n = len(nums1)
        n122times = dict()
        n342times = dict()
        for i in range(n):
            for j in range(n):
                ts = nums1[i]+nums2[j]
                if ts in n122times:
                    n122times[ts] += 1
                else:
                    n122times[ts] = 1
        for i in range(n):
            for j in range(n):
                ts = nums3[i]+nums4[j]
                if ts in n342times:
                    n342times[ts] += 1
                else:
                    n342times[ts] = 1
        ans = 0
        for k in n122times:
            if -k in n342times:
                ans += n122times[k]*n342times[-k]
        return ans
# @lc code=end

