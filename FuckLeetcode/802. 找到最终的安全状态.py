class Solution:
    def eventualSafeNodes(self, graph):
        node_num = len(graph)
        safe = [0]*node_num

        def dfs(node):
            '''
            return bool
                True: meaning this node safe
                False: meaning this node no-safe
            '''
            if safe[node] == 1:
                return False
            elif safe[node] == 2:
                return True
            this_node_status = True
            safe[node] = 1
            for to_node in graph[node]:
                this_node_status *= dfs(to_node)
            if this_node_status:
                safe[node] = 2
                return True
            else:
                return False
        for i in range(node_num):
            if safe[i] == 0:
                dfs(i)
        ans = []
        for i in range(node_num):
            if safe[i] == 2 or safe[i] == 0:
                ans.append(i)
        return ans
s = Solution()
print(s.eventualSafeNodes(
    # [[1,2],[2,3],[5],[0],[5],[],[]]
    #  [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    [[0],[2,3,4],[3,4],[0,4],[]]
))        