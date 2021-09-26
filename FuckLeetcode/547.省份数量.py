class Solution:
    def findCircleNum(self, isConnected: [[int]]) -> int:
        n = len(isConnected)
        fa = [i for i in range(n)]
        rank = [0]*n

        def find(x):
            fa[x] = x if fa[x]==x else find(fa[x])
            return fa[x]

        def merge(i, j):
            ifa = find(i)
            jfa = find(j)
            if rank[i] <= rank[j]:
                fa[ifa] = jfa
            else:
                fa[jfa] = ifa
            if rank[ifa]==rank[jfa] and ifa!=jfa:
                rank[jfa] += 1

        for i,con in enumerate(isConnected):
            for j,c in enumerate(con):
                if c:
                    merge(i, j)
        # print(fa)
        ans = set()
        for f in fa:
            ans.add(find(f))
        return len(ans)
s = Solution()
print(s.findCircleNum(
    #  [[1,1,0],[1,1,0],[0,0,1]]
    #  [[1,0,0],[0,1,0],[0,0,1]]
    [[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]
))