class Solution:
    def trap(self, height) -> int:
        n = len(height)
        if n<=2:
            return 0
        lb = [0]*n
        rb = [0]*n
        lb[0] = height[0]
        rb[-1] = height[-1]
        for i in range(1, n):
            lb[i] = max(lb[i-1], height[i])
        for i in range(n-2, -1, -1):
            rb[i] = max(rb[i+1], height[i])
        ans = [min(lb[i], rb[i])-height[i] for i in range(n)]

        # print(lb, rb, ans)
        return sum(ans)

s = Solution()
print(s.trap(
    [4,2,0,3,2,5]
    # [0,1,0,2,1,0,1,3,2,1,2,1]
))
        
