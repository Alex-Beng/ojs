from copy import deepcopy

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]: 
        
        def dfs(n, layer, used, curr, ans):
            if layer == n:
                # print(curr)
                ans.append(deepcopy(curr))
            else:
                for i in range(n):
                    if not used[i]:
                        used[i] = 1
                        curr.append(i)
                        dfs(n, layer+1, used, curr, ans)
                        used[i] = 0
                        del curr[-1]
        
        perm = []
        n = len(nums)
        used = [0]*10

        dfs(n, 0, used, [], perm)
        # print(perm)

        ans = []
        app = dict()
        for p in perm:
            # print(p)
            t = [nums[i] for i in p]
            tt = tuple(t)
            if tt in app:
                continue
            else:
                app[tt] = 1
                ans.append(t)
        return ans