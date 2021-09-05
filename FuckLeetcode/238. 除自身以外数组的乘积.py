class Solution:
    def productExceptSelf(self, nums: [int]) -> [int]:
        n = len(nums)
        pre_prod = [1]*(n+1)
        tai_prod = [1]*(n+1)
        for i in range(n):
            pre_prod[i] = pre_prod[i-1]*nums[i]
        for i in range(n-1, -1, -1):
            tai_prod[i] = tai_prod[i+1]*nums[i]
        ans = [1]*n
        for i in range(n):
            ans[i] = pre_prod[i-1]*tai_prod[i+1]
        return ans
s = Solution()
s.productExceptSelf(
    [1,2,3,4]
)
