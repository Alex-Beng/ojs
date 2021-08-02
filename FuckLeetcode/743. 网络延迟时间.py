class Solution:
    def networkDelayTime(self, times, n: int, k: int) -> int:
        graph = dict()
        for i in range(1, n+1):
            graph[i] = dict()
        for edge in times:
            graph[edge[0]][edge[1]] = edge[2]
        
        all_node = {i for i in range(1, n+1)}
        t_node = {k}
        
        dist = [float('inf')]*(n+1)
        dist[k] = 0
        
        while True:
            min_path = float('inf')
            min_idx = -1
            for n in t_node:
                for ntr in graph[n].keys():
                    # print(ntr)
                    if ntr not in t_node and dist[n]+graph[n][ntr] < min_path:
                        min_path = dist[n]+graph[n][ntr]
                        min_idx = ntr
            if min_path == float('inf'):
                return -1
            else:
                t_node |= {min_idx}
                dist[min_idx] = min_path
            if t_node == all_node:
                break
            # print(dist, t_node, all_node)
        return max(dist[1:])
s = Solution()
print(s.networkDelayTime(
    #  [[2,1,1],[2,3,1],[3,4,1]],
    #  4, 2

    [[1,2,1]],
    2,2
))
