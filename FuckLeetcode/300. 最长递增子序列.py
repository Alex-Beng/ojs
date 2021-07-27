class Solution:
    def lengthOfLIS(self, nums) -> int:
        '''
        Naive Way
        最简单的 O(n^2) 做法
        子问题定义：dp[i]：以nums[i]结尾的最长子序列长度
        dp[i] = max(dp[j]) + 1, j < i and nums[j] < nums[i]
        
        '''
        n = len(nums)
        dp = [0]*n
        dp[0] = 1
        for i in range(1, n):
            max_idx = -1
            max_val = -1
            for j in range(0, i):
                if nums[i] > nums[j] and dp[j] > max_val:
                    max_idx = j
                    max_val = dp[j]
            
            dp[i] = dp[max_idx]+1 if max_idx != -1 else 1
            # print(dp)
        return max(dp)
    
    def lengthOfLIS(self, nums) -> int:
        '''
        An un-intuitive Way
        O(nlogn) 
        子问题定义：dp[i]：长度为i的最长子序列的结尾

        dp 与 i 严格正相关，证明：
        if i>j, assume dp[i]<=dp[j]
        => dp[j-(j-i)] < dp[j] => dp[i] < dp[j]，矛盾，成立

        for n in nums:
            if dp[len] < n:
                dp[len++] = n
            else:
                bin_search(i) while dp[i]>= n >dp[i-1]
                dp[i] = n
        '''
        n = len(nums)
        ans = 1
        dp = [0]*n
        dp[0] = nums[0]
        for i in range(1, n):
            num = nums[i]
            if dp[ans-1] < num:
                dp[ans] = num
                ans += 1
            else:
                l = 0
                r = ans
                while l<r:
                    m = l + (r-l)//2
                    if dp[m] < num:
                        l = m+1
                    else:
                        r = m
                dp[l] = num
                # print(l)
                # print(dp)
                # print(dp[l])
        return ans
                        
            
                    
s = Solution()
# s.lengthOfLIS([1,3,6,7,9,4,10,5,6])
s.lengthOfLIS([1,3,4,2])