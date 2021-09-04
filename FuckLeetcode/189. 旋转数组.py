class Solution:
    def rotate(self, nums: [int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        last_k = []
        for i in range(-k, 0):
            last_k.append(nums[i])
        # print(last_k)
        
        for i in range(-1, -n+k-1, -1):
            nums[i] = nums[i-k]
            # print(nums)
        for i in range(k):
            nums[i] = last_k[i]
s = Solution()
ya = [1,2,3,4,5,6,7]
s.rotate(
    ya, 3
)
print(ya)