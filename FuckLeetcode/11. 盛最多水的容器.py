class Solution:
    def maxArea(self, height: [int]) -> int:
        n = len(height)
        l = 0
        r = n-1
        ans = -1
        while l<r:
            l_h = height[l]
            r_h = height[r]
            min_h = min(l_h, r_h)

            t_area = (r-l)*min_h
            ans = max(t_area, ans)
            if min_h == l_h:
                l += 1
            else:
                r -= 1
        return ans
s = Solution()
print(s.maxArea(
    # [1,8,6,2,5,4,8,3,7]
    #  [4,3,2,1,4]
    # [1,1]
     [1,2,1]
))