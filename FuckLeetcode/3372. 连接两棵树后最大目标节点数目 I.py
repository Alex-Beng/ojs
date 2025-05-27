from typing import List

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        def build_graph_from_edges(edges, num_nodes):
            graph = {i: [] for i in range(num_nodes)}
            for u, v in edges:
                graph[u].append(v)
                graph[v].append(u)
            return graph
        N, M = len(edges1) + 1, len(edges2) + 1

        def dfs(graph, node, parent, depth, distances):
            distances[depth] = distances[depth] + 1
            for neighbor in graph[node]:
                if neighbor != parent:
                    dfs(graph, neighbor, node, depth + 1, distances)

        def calculate_distances_for_all_nodes(edges, num_nodes):
            graph = build_graph_from_edges(edges, num_nodes)
            all_distances = []

            for node in range(num_nodes):
                distances = [0] * num_nodes
                dfs(graph, node, -1, 0, distances)
                all_distances.append(distances)

            return all_distances

        all_distances1 = calculate_distances_for_all_nodes(edges1, N)
        all_distances2 = calculate_distances_for_all_nodes(edges2, M)

        accD1 = [[0]*N for _ in range(N)]
        accD2 = [[0]*M for _ in range(M)]
        
        maxCol2 = [0] * M
        for i in range(k+1):
            for j in range(max(N, M)):
                if j < N and i < N:
                    accD1[j][i] = accD1[j][i-1] + all_distances1[j][i]
                if j < M and i < M:
                    accD2[j][i] = accD2[j][i-1] + all_distances2[j][i]
                    maxCol2[i] = max(maxCol2[i], accD2[j][i])
        res = []
        for i in range(N):
            if k-1 >= 0 and k-1 < len(maxCol2):
                p1 = maxCol2[k-1]
            elif k == 0:
                p1 = 0
            else:
                p1 = maxCol2[-1]
            
            if k >= 0 and k < len(accD1[i]):
                p2 = accD1[i][k]
            else:
                p2 = accD1[i][-1]
            res.append(p1 + p2)
        return res
        return [maxCol2[k-1] + accD1[i][k] for i in range(N)]        

INPUT = [
    ([[0,1],[0,2],[2,3],[2,4]], [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], 2),
    ([[0,1],[0,2],[0,3],[0,4]], [[0,1],[1,2],[2,3]], 1),
    ([[0,1]], [[0,1],[1,2]], 2),
    ([[0,1],[1,2]], [[0,1]], 2)
]