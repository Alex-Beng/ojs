class Solution:
    def canJump_n2(self, nums) -> bool:
        '''
        傻逼O(n^2)做法
        '''
        n = len(nums)
        dp = [0]*n
        dp[0] = 1
        for i in range(n):
            if dp[i]: # jump-able
                for j in range(i, min(i+nums[i]+1, n)):
                    if j == n-1:
                        return True
                    dp[j] = 1
        return False
    def canJump(self, nums) -> bool:
        '''
        O(n)的BFS
        '''
        n = len(nums)
        max_idx = 0
        for i in range(n):
            if i<=max_idx:
                max_idx = max(max_idx, i+nums[i])
            else:
                return False
        return True

                    
s = Solution()
print(s.canJump([2,3,1,1,4]))