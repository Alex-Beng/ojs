from copy import deepcopy
class Solution:
    def permute(self, nums):
        
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
        for p in perm:
            # print(p)
            ans.append([nums[i] for i in p])
        return ans
        
s = Solution()
print(s.permute([1,2,3]))