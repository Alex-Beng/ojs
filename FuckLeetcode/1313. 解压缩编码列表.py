class Solution:
    def decompressRLElist(self, nums):
        n = len(nums)
        ans = []
        for i in range(0, n, 2):
            # print(i)
            ans += [nums[i+1]]*nums[i]
        return ans
s = Solution()
print(s.decompressRLElist(
    # list(range(8))
    [1,2,3,4]
))