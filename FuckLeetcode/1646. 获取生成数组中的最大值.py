class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if not n:
            return n
        nums = [0]*(n+1)
        nums[1] = 1

        for t in range(2, n+1):
            i = t//2
            # print(t, i)
            if t&1:
                nums[t] = nums[i]+nums[i+1]
            else:
                nums[t] = nums[i]
        # print(nums)
        return max(nums)
s = Solution()
print(s.getMaximumGenerated(
    7
))
            