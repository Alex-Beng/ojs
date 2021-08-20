class Solution:
    def sortColors(self, nums: [int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        ones = 0
        twos = 0
        for t in nums:
            if t==1:
                ones+=1
            elif t==2:
                twos+=1
        # print(n-ones-twos, n, ones, twos)
        nums[::] = [0]*(n-ones-twos) + [1]*ones + [2]*twos
        # print(nums)
s = Solution()
a = [1,1,1,2,2,2,0,0,0]
s.sortColors(a)
print(a)
