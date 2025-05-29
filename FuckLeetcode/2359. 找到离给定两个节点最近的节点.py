from typing import List

class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        N = len(edges)

        dis1 = [-1] * N
        dis2 = [-1] * N
        
        def dfs(curr, dis, depth):
            if dis[curr] == -1:
                dis[curr] = depth
            else:
                return
            
            if edges[curr] != -1:
                dfs(edges[curr], dis, depth+1)

        dfs(node1, dis1, 0)
        dfs(node2, dis2, 0)

        minBDis = float('inf')
        minBDisIdx = -1
        for i in range(N-1, -1, -1):
            if dis1[i] != -1 and dis2[i] != -1 and (m := max(dis1[i], dis2[i])) <= minBDis:
                minBDis = m
                minBDisIdx = i
                # print(m, i)
        return minBDisIdx
INPUT = [
    # ([2,2,3,-1], 0, 1),
    # ([1,2,-1], 0, 2)
    ([5,3,1,0,2,4,5], 3, 2)
]