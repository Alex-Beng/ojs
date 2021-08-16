from collections import defaultdict
class Solution:
    def countArrangement(self, n: int) -> int:
        # !!!! 
        # DP 建立在第i位可与其因数上的数随意换位，但是6与2(上面是4)位不可替换。
        # DP 不成立

        # dp_one[i][j] 长度为i，第j位为1的优美排序数
        # dp_one[i][j] j \in [1, i-1],  dp_one[i][j] = dp_one[i-1][j]*(i除1外的因数数量)
        #                               dp_one[i][i] = sum(for ft in i'fts)(dp_one[i-1][ft])
        dp_one = [[0]*(n+1) for i in range(n+1) ]
        # dp[i] 为长度为i的排序，其所有的优美排序数
        # dp[i] = dp[i-1]*(i除1外的因数数量) + dp_one[i][i]
        dp = [0]*(n+1)

        dp_one[1][1] = 1
        dp[1] = 1

        def fators(t):
            ans = 0
            fts = []
            for i in range(2, t+1):
                if t%i == 0:
                    ans += 1
                    fts.append(i)
            return ans,fts+[1]

        for i in range(2, n+1):
            ft_num, fts = fators(i)
            for j in range(1, i):
                dp_one[i][j] = dp_one[i-1][j]*ft_num

            dp_one[i][i] = sum([dp_one[i-1][ft] for ft in fts])
            # print(dp_one[i][1:])
            dp[i] = dp[i-1]*ft_num + dp_one[i][1]
            
        print(dp)
        return dp[n]

    def countArrangement(self, n: int) -> int:
        can_set = [set() for _ in range(n+1)]
        for i in range(1, n+1):
            for j in range(1, n+1):
                if i%j==0 or j%i == 0:
                    can_set[i].add(j)
        ans = 0
        vis = 0
        def dfs(layer):
            nonlocal ans, vis
            if layer == n+1:
                ans += 1
                return 
            for i in  can_set[layer]:
                if not vis&(1<<i):
                    vis |= (1<<i)
                    dfs(layer+1)
                    vis -= (1<<i)

        dfs(1)
        return ans
                    

s = Solution()
# print(s.countArrangement(2))
# exit()

for i in range(1, 16):
    print(s.countArrangement(
        i
    ))

