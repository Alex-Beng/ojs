class Solution:
    def largestRectangleArea(self, heights: [int]) -> int:
        heights = [0] + heights + [0]
        
        sk = []
        ans = 0
        for i,h in enumerate(heights):
            if len(sk)==0:
                sk.append(i)
                continue
            # pop
            while len(sk) and h < heights[sk[-1]]:

                j = sk.pop()
                th = heights[j]
                tw = i-sk[-1]-1
                ans = max(ans, th*tw)

            sk.append(i)
        return ans
                    

s = Solution()
r = s.largestRectangleArea(
    # [1,2,2]
    # [2,4]
    #  [2,1,5,6,2,3]
    [3,6,5,7,4,8,1,0]
    # [2,1,2]

)
print(r)