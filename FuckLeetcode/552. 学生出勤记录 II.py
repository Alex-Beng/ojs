from functools import lru_cache
import sys
sys.setrecursionlimit(1002333)

MOD = 1000000007
class Solution:
    def checkRecord(self, n: int) -> int:
        '''
        TLE WITH MEMO SEARCH
        '''
        ans = 0
        curr = []
        # @lru_cache(None)
        memo = dict()
        def dfs(curr_idx, a_num, l_num):
            if (curr_idx, a_num, l_num) in memo:
                return memo[(curr_idx, a_num, l_num)]
            # print(curr_idx, a_num, l_num)
            if curr_idx>=n:
                # print(curr)
                return 1
            # curr.append('P')
            t_ans = 0
            t_ans += dfs(curr_idx+1, a_num, 2)
            # del curr[-1]

            if a_num>0:
                # curr.append('A')
                t_ans += dfs(curr_idx+1, a_num-1, 2)# 傻逼啊，这里应该是２而不是l_num
                # del curr[-1]
            if l_num>0:
                # curr.append('L')
                t_ans += dfs(curr_idx+1, a_num, l_num-1)
            #     del curr[-1]
            memo[(curr_idx, a_num, l_num)] = t_ans
            return t_ans
        
        ans = dfs(0, 1, 2)%MOD
        # print(n, ans)
        return ans
    def checkRecord(self, n: int) -> int:
        # dp = [ [[0,0,0], [0,0,0]] for i in range(n+1)]
        # dp[0][0][0] = 1
        dp = [[0,0,0], [0,0,0]]
        dp[0][0] = 1
        new_dp = [[0,0,0], [0,0,0]]
        for i in range(1, n+1):
            new_dp = [[0,0,0], [0,0,0]]

            # place P
            new_dp[0][0] = (sum(dp[0]))%MOD
            new_dp[1][0] = (sum(dp[1]))%MOD
            # place A
            new_dp[1][0] += sum(dp[0])
            new_dp[1][0] %= MOD
            # place L
            new_dp[0][1] = dp[0][0]
            new_dp[0][2] = dp[0][1]
            new_dp[1][1] = dp[1][0]
            new_dp[1][2] = dp[1][1]
    
            dp = new_dp
        ans = 0
        for i in range(2):
            for j in range(3):
                ans += dp[i][j]
        return ans%(int(1e9+7))
    def checkRecord(self, n: int) -> int:
        trans_mat = [
            [1,1,1,0,0,0],
            [1,0,0,0,0,0],
            [0,1,0,0,0,0],
            [1,1,1,1,1,1],
            [0,0,0,1,0,0],
            [0,0,0,0,1,0]
        ]
        # 撸个快速幂得了
        def multiply(mata, matb):

            row = len(mata)
            col = len(matb[0])
            # print(row, col)
            ans = [[0]*col for _ in range(row)]
            # # print(ans)
            # for r in ans:
            #     print(r)

            for i in range(row):
                for j in range(col):
                    t_ans = 0
                    for k in range(len(mata[0])):
                        t_ans += mata[i][k]*matb[k][j]
                    ans[i][j] = t_ans%MOD
            # # print(ans)
            # for r in ans:
            #     print(r)
            return ans
        eye = [
            [1,0,0,0,0,0],
            [0,1,0,0,0,0],
            [0,0,1,0,0,0],
            [0,0,0,1,0,0],
            [0,0,0,0,1,0],
            [0,0,0,0,0,1]
        ]
        def fast_power(mat, n):
            if n==0:
                return eye
            elif n==1:
                return mat
            
            if n%2==0:
                half_n = n//2
                t = fast_power(mat, half_n)
                return multiply(t, t)
            else:
                half_n = (n-1)//2
                t = fast_power(mat, half_n)
                return multiply(mat, multiply(t, t))
        init = [
            [1],
            [0],
            [0],
            [0],
            [0],
            [0],
        ]
        t_mat = fast_power(trans_mat, n)
        ans = multiply(t_mat, init)
        return sum([i[0] for i in ans])%MOD
        # print(ans)
                
            
s = Solution()
# print(s.checkRecord(
#     # 100000
#     # 100000
#     3

# ))
for t in range(1, 100):
    # t = int(input())
    print(t,  s.checkRecord(
        # 10101
        t
        # 3
    ))
            
            
            