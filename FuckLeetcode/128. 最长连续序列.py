class Solution:
    def longestConsecutive(self, nums: [int]) -> int:
        if len(nums)==0:
            return 0
        nums = set(nums)
        next_num = dict()
        for n in nums:
            next_num[n] = 0
        for n in nums:
            if (n+1) in next_num and next_num[n]==0:
                t = n
                while t in next_num:
                    next_num[t] = next_num[t-1]+1 if t-1 in next_num else 1
                    t += 1
                    # print(next_num)
        return max(max(next_num.values()), 1)
s = Solution()
print(s.longestConsecutive(
     [0]
))