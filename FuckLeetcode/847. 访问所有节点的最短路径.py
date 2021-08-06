from collections import deque
class Solution:
    def shortestPathLength(self, graph) -> int:
        n = len(graph)
        q = deque((i, 1<<i, 0) for i in range(n))
        been = {(i, 1<<i) for i in range(n)}
        ans = 0

        while q:
            idx, mask, dist = q.popleft()
            if mask == (1<<n)-1:
                ans = dist
                break
            for to_node in graph[idx]:
                t_mask |= (1<<to_node)
                if (to_node, t_mask) not in been:
                    q.append((to_node, t_mask, dist+1))
                    been.add((to_node, t_mask))
        return ans


s = Solution()
print(s.shortestPathLength(
    #  [[1,2,3],[0],[0],[0]]
    #  [[1],[0,2,4],[1,3,4],[2],[1,2]]
    # [[1],[0,2,4],[1,3],[2],[1,5],[4]]
    # [[1,4],[0,3,10],[3],[1,2,6,7],[0,5],[4],[3],[3],[10],[10],[1,9,8]]
    [[1,2,3,4,5,6,7,8,9,10,11],[0,2,5,6,8],[0,1,4,5,6,9,10,11],[0,4,5,6,8,9,10,11],[0,2,3,5,6,8,10],[0,1,2,3,4,6,8,9,10,11],[0,1,2,3,4,5,8,10,11],[0,8],[0,1,3,4,5,6,7,9,10,11],[0,2,3,5,8,10],[0,2,3,4,5,6,8,9],[0,2,3,5,6,8]]
))