class Solution:
    def maxProductDifference(self, nums) -> int:
        l1 = l2 = float('-inf')
        s1 = s2 = float('inf')
        for num in nums:
            if num > l1:
                l2 = l1
                l1 = num
            elif num > l2:
                l2 = num
                
            if num < s1:
                s2 = s1
                s1 = num
            elif num < s2:
                s2 = num
            # print(s1, s2, l1, l2)
        return l1*l2 - s1*s2

    def maxProductDifference(self, nums) -> int:
        '''
        using sort
        '''
        # l1 = l2 = float('-inf')
        # s1 = s2 = float('inf')
        s_nums = sorted(nums)
        s1, s2 = s_nums[:2]
        l1, l2 = s_nums[-2:]
        # print(s1, s2, l1, l2)
        return l1*l2 - s1*s2

s = Solution()
print(s.maxProductDifference([5,6,2,7,4]))