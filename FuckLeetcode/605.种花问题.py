#
# @lc app=leetcode.cn id=605 lang=python3
#
# [605] 种花问题
#

# @lc code=start
class Solution:
    def canPlaceFlowers(self, flowerbed: [int], n: int) -> bool:
        nn = n
        n = len(flowerbed)

        ans = 0
        i = 0
        while i<n:
            # print(i)
            if flowerbed[i]:
                i += 1
            else:
                j = i
                while j<n and flowerbed[j]==0:
                    j += 1
                
                if i==0 and j==n:    
                    ans += (j-i+1)//2
                elif i==0 or j==n:
                    ans += (j-i)//2
                else:
                    # print(j-i, (j-i-1)//2)
                    ans += (j-i-1)//2
                i = j
        # print(ans)
        return ans >= nn
                
                
        
# @lc code=end

s = Solution()
s.canPlaceFlowers(
    # [1,0,0,0,0,1], 2
    # [1,0,0,0,1,0,0], 2
    [0], 1
)