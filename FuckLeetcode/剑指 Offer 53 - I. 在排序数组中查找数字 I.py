class Solution:
    def search(self, nums: [int], target: int) -> int:
        n = len(nums)
        if n==1:
            return 1 if nums[0]==target else 0
        L = 0
        R = n-1
        lb = -1
        while L<=R:
            m = (L+R)//2
            if nums[m] < target:
                L = m+1
                lb = m
            else:
                R = m-1
        L = 0
        R = n-1
        rb = n
        while L<=R:
            m = (L+R)//2
            if nums[m] > target:
                R = m-1
                rb = m
            else:
                L = m+1
        print(lb, rb)
        return max(rb-lb-1, 0)
s = Solution()
s.search(
    [1,1],1
)