class Solution:
    def getRow(self, rowIndex: int):
        ans = [1]*(rowIndex+1)
        for r in range(2, rowIndex+1):
            # print(ans[:r])
            p_num = ans[0]
            for i in range(1, r):
                # print("ya")
                t = ans[i]
                ans[i] += p_num
                p_num = t
        # print(ans)
        return ans
s = Solution()
s.getRow(
    3
)