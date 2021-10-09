class Solution:
    def maximalRectangle(self, matrix: [[str]]) -> int:
        if len(matrix) == 0:
            return 0
            
        row = len(matrix)
        col = len(matrix[0])
        up = [[0]*col for _ in range(row)]
        for c in range(col):
            for r in range(row):
                if r==0:
                    up[r][c] = 1 if matrix[r][c]=='1' else 0
                else:
                    up[r][c] = up[r-1][c]+1 if matrix[r][c]=='1' else 0

        ans = 0
        for r in range(row):
            heights = [0] + up[r] + [0]
            sk = []
            
            for i,h in enumerate(heights):
                if len(sk)==0:
                    sk.append(i)
                    continue
                while len(sk) and h < heights[sk[-1]]:
                    j = sk.pop()
                    th = heights[j]
                    tw = i-sk[-1]-1
                    ans = max(ans, th*tw)
                sk.append(i)
        return ans
            


s = Solution()
r = s.maximalRectangle(
    [["1","0","1","0","0"],
     ["1","0","1","1","1"],
     ["1","1","1","1","1"],
     ["1","0","0","1","0"]]
)
print(r)