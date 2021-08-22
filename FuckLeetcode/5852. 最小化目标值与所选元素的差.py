from functools import lru_cache
class Solution:
    def minimizeTheDifference(self, mat: [[int]], target: int) -> int:
        row = len(mat)
        col = len(mat[0])

        ans = float('inf')
        @lru_cache(None)
        def dfs(layer, curr_sum):
            nonlocal ans
            if layer == row-1:
                for n in mat[layer]:
                    ans = min(ans, abs(target-curr_sum-n))
                # ans = min(ans, abs(target-curr_sum))
                return
            
            for n in mat[layer]:
                # if curr_sum+n > target and curr_sum > target:
                    # continue
                # if curr_sum>ans:
                    # continue
                if curr_sum+n>target and curr_sum+n-target>ans:
                    continue
                dfs(layer+1, curr_sum+n)
        dfs(0, 0)
        return ans
s = Solution()
print(s.minimizeTheDifference(
    [[1,2,3],[4,5,6],[7,8,9]], 13
    # [[1],[2],[3]], 100
    # [[1,2,9,8,7]], 6
    # [[1,2,9,8,7]], 6
))
