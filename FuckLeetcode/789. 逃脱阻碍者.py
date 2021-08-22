class Solution:
    def escapeGhosts(self, ghosts: [[int]], target: [int]) -> bool:
        def man_dist(p1, p2):
            return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])
        g_dist = [man_dist(p, target) for p in ghosts]
        m_dist = man_dist((0,0), target)
        for g_d in g_dist:
            if g_d<=m_dist:
                return False
        return True
s = Solution()
print(s.escapeGhosts(
    # [[1,0],[0,3]], [0,1]
    # [[1,0]], [2,0]
    # [[2,0]], [1,0]
    # [[5,0],[-10,-2],[0,-5],[-2,-2],[-7,1]], [7,7]
    [[-1,0],[0,1],[-1,0],[0,1],[-1,0]], [0,0]
))