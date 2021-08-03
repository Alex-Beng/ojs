class Solution:
    def generate(self, numRows: int):
        ans = []
        ans.append([1])
        for r_num in range(2, numRows+1):
            ans.append([1]*r_num)
            for c in range(1, r_num-1):
                # print(ans[r_num-2][c])
                ans[r_num-1][c] = ans[r_num-2][c] + ans[r_num-2][c-1]
        return ans

s = Solution()
print(s.generate(7))