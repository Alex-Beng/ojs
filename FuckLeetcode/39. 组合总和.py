class Solution:
    def combinationSum(self, candidates: [int], target: int) -> [[int]]:
        n = len(candidates)
        candidates.sort()

        ans = set()
        curr = []
        def dfs(curr_sum):
            if curr_sum >= target:
                if curr_sum==target:
                    # print(curr)
                    ans.add(tuple(sorted(curr)))
                return 
            
            for i in range(n):
                curr.append(candidates[i])
                dfs(curr_sum+candidates[i])
                del curr[-1]
        # for ly in range(1, target+1):
        #     max_layer = ly
        dfs(0)
        # print(ans, [list(i) for i in ans])
        return [list(i) for i in ans]
s = Solution()
s.combinationSum(
    # [2,3,6,7], 7
    # [2,3,5], 8
    # [1], 1
    [92,71,89,74,102,91,70,119,86,116,114,106,80,81,115,99,117,93,76,77,111,110,75,104,95,112,94,73],310
)