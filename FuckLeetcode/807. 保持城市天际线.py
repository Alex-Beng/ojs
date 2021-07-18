class Solution:
    def maxIncreaseKeepingSkyline(self, grid) -> int:
        width = len(grid[0])
        height = len(grid)
        ud_sky_lines = [max([ grid[j][i] for j in range(height) ]) for i in range(width)]
        rl_sky_lines = [max(grid[i]) for i in range(height)]
        ans = 0
        for r in range(width):
            for c in range(height):
                ans += min(ud_sky_lines[c], rl_sky_lines[r]) - grid[r][c]

        # print(ud_sky_lines, rl_sky_lines)
        # print(ans)
        return ans
        
s = Solution()
s.maxIncreaseKeepingSkyline( [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]])