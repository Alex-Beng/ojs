from copy import deepcopy
class Solution:
    def allPathsSourceTarget(self, graph: [[int]]) -> [[int]]:
        n = len(graph)
        ans = []

        def dfs(curr_node, curr_path):
            if curr_node == n-1:
                ans.append(tuple(curr_path))
                return 
            
            for to in graph[curr_node]:
                curr_path.append(to)
                dfs(to, curr_path)
                del curr_path[-1]
        dfs(0, [0])
        # print(ans)
        return [list(i) for i in ans]
s = Solution()
s.allPathsSourceTarget(
    #  [[1,2],[3],[3],[]]
    [[4,3,1],[3,2,4],[3],[4],[]]
)