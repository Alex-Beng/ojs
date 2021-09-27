#
# @lc app=leetcode.cn id=797 lang=python3
#
# [797] 所有可能的路径
#

# @lc code=start
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
        return [list(i) for i in ans]
# @lc code=end

