class Solution:
    def getMaxLen(self, nums) -> int:
        n = len(nums)
        dp_pos = [0]*n
        dp_neg = [0]*n

        dp_pos[0] = 1 if nums[0] > 0 else 0
        dp_neg[0] = 1 if nums[0] < 0 else 0
        for i in range(1, n):
            if nums[i] > 0:
                dp_pos[i] = dp_pos[i-1]+1 
                dp_neg[i] = dp_neg[i-1]+1 if dp_neg[i-1]!=0 else 0
            elif nums[i] < 0:
                dp_pos[i] = dp_neg[i-1]+1 if dp_neg[i-1]!=0 else 0
                dp_neg[i] = dp_pos[i-1]+1 
            else:
                dp_pos[i] = 0
                dp_neg[i] = 0
            # print(dp_pos, dp_neg)
        return max(dp_pos)
s = Solution()
print(s.getMaxLen( [0,1,-2,-3,-4]))