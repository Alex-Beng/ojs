class Solution:
    def combine(self, n: int, k: int) -> [[int]]:
        
        curr = []
        ans = []
        def dfs(layer, vis, last_vis):
            if layer>=k:
                # print(curr)
                ans.append(tuple(curr))
                return 
            for i in range(last_vis+1,n+1):
                if not vis&(1<<i):
                    curr.append(i)
                    dfs(layer+1, vis|(1<<i), i)
                    del curr[-1]
        dfs(0,0,0)
        # print(ans)
        return [list(i) for i in ans]
s = Solution()
s.combine(
    # 4,2
    1,1
)
