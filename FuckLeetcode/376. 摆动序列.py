class Solution:
    def wiggleMaxLength(self, nums) -> int:
        n = len(nums)
        dp_up = [1]*n
        dp_dn = [1]*n

        for i in range(1, n):
            if nums[i] > nums[i-1]:
                dp_up[i] = max(dp_up[i-1], dp_dn[i-1]+1)
                dp_dn[i] = dp_dn[i-1]        
            elif nums[i] < nums[i-1]:
                dp_up[i] = dp_up[i-1]
                dp_dn[i] = max(dp_up[i-1]+1, dp_dn[i-1])
            else:
                dp_up[i] = dp_up[i-1]
                dp_dn[i] = dp_dn[i-1]
        return max(max(dp_up), max(dp_dn))
s = Solution()
print(s.wiggleMaxLength(
    # [1,7,4,9,2,5]
    #  [1,17,5,10,13,15,10,5,16,8]
     [1,2,3,4,5,6,7,8,9]
))   