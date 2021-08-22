from copy import deepcopy
class Solution:
    def subsets(self, nums: [int]) -> [[int]]:
        n = len(nums)
        ans = [[]]

        been = set()
        def dfs(layer, max_layer, curr_ans, k):
            if layer==max_layer:
                ans.append([nums[i] for i in curr_ans])
                return 
            else:
                for i in range(k, n):
                    if i not in been:
                        been.add(i)
                        curr_ans.append(i)
                        dfs(layer+1, max_layer, curr_ans, i+1)
                        been.remove(i)
                        del curr_ans[-1]
        
        for l in range(1, n+1):
            dfs(0, l, [], 0)
        # print(ans)
        return ans
s = Solution()
s.subsets(
     [1,2,3]
)