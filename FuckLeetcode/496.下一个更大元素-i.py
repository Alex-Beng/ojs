#
# @lc app=leetcode.cn id=496 lang=python3
#
# [496] 下一个更大元素 I
#

# @lc code=start
class Solution:
    def nextGreaterElement(self, nums1: [int], nums2: [int]) -> [int]:
        l2 = len(nums2)

        snum2 = sorted(nums2)
        n2idx = dict()
        for i,n in enumerate(nums2):
            n2idx[n] = i
        ans = [-1]*len(nums1)
        for i,n in enumerate(nums1):
            idx = n2idx[n]
            idx += 1
            while idx<l2:
                if nums2[idx] > n:
                    ans[i] = nums2[idx]
                    break
                idx += 1
        return ans
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums2)
        next_big = [-1]*n
        sk = []
        num2idx = dict()
        for i,n in enumerate(nums2):
            num2idx[n] = i
            while len(sk) and n > nums2[sk[-1]]:
                next_big[sk[-1]] = i
                del sk[-1]
            sk.append(i)
        ans = []
        for i,n in enumerate(nums1):
            b_idx = next_big[num2idx[n]]
            if b_idx == -1:
                ans.append(-1)
            else:
                ans.append(nums2[b_idx])
        return ans

# @lc code=end

s = Solution()
print(s.nextGreaterElement(
    [4,1,2], [1,3,4,2]
    # [2,4], [1,2,3,4]
))