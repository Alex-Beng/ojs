class Solution:
    def generateMatrix(self, n: int) -> [[int]]:
        ans = [[0]*n for _ in range(n)]
        row, col = 0, 0
        cnt = 1
        ans[row][col] = cnt
        cnt += 1
        while cnt <= n*n:
            # ans[row][col] = cnt
            # cnt += 1
            while col+1<n and ans[row][col+1]==0:
                col += 1
                ans[row][col] = cnt
                cnt += 1
            while row+1<n and ans[row+1][col]==0:
                row += 1
                ans[row][col] = cnt
                cnt += 1
            while col-1>=0 and ans[row][col-1]==0:
                col -= 1
                ans[row][col] = cnt
                cnt += 1
            while row-1>=0 and ans[row-1][col]==0:
                row -= 1
                ans[row][col] = cnt
                cnt += 1
        # for t in ans:
        #     print(t)
        # print(ans)
        return ans
s = Solution()
s.generateMatrix(
    8
)