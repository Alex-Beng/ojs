from typing import List

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        N, M = len(edges1)+1, len(edges2)+1
        node2odd1 = [0] * N
        node2odd2 = [0] * M
        odd2num1 = [0] * 2
        odd2num2 = [0] * 2
        

        def edge2aj(edges):
            res = {}
            for u, v in edges:
                res[u] = res.get(u, [])
                res[v] = res.get(v, [])
                res[u].append(v)
                res[v].append(u)
            return res

        aj1 = edge2aj(edges1)
        aj2 = edge2aj(edges2)

        def dfs(curr, last, depth, aj, res, resNum):
            res[curr] = depth % 2
            resNum[res[curr]] += 1
            for next in aj[curr]:
                if next != last:
                    dfs(next, curr, depth+1, aj, res, resNum)
        dfs(0, -1, 0, aj1, node2odd1, odd2num1)
        dfs(0, -1, 0, aj2, node2odd2, odd2num2)

        res = []
        for i in range(N):
            p1 = odd2num1[node2odd1[i]]
            # p2 = odd2num2[1-node2odd1[i]]
            p2 = max(odd2num2)
            print(i, p1, p2)
            res.append(p1+p2)
        return res
        pass
INPUT = [
    ([[0,1],[0,2],[2,3],[2,4]], [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]])
]
        