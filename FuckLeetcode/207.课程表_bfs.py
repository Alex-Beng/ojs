#
# @lc app=leetcode.cn id=207 lang=python3
#
# [207] 课程表
#

# @lc code=start
from queue import Queue

class Solution:
    def canFinish(self, numCourses: int, prerequisites: [[int]]) -> bool:
        n = numCourses
        aj_mat = [[0]*n for _ in range(numCourses)]
        in_deg = [0]*n
        out_deg = [0]*n
        for f,t in prerequisites:
            in_deg[t] += 1
            out_deg[f] += 1
            aj_mat[f][t] = 1

        pos_beg = []
        for i,odeg in enumerate(out_deg):
            if odeg == 0:
                pos_beg.append(i)
        if len(pos_beg)==0:
            return False


        been = [0]*n
        que = Queue()
        for b in pos_beg:
            que.put(b)
            been[b] = 1

        while not que.empty():
            tt = que.get()

            for tf in range(n):
                if aj_mat[tf][tt] and not been[tf]:
                    in_deg[tt] -= 1
                    out_deg[tf] -= 1
                    if out_deg[tf]==0:
                        que.put(tf)
                        been[tf] = 1
        return sum(been)==n


# @lc code=end

s = Solution()
r = s.canFinish(
    # 3, [[1,0],[1,2],[0,1]]
    # 2, [[1,0]]
    # 8, [[1,0],[2,6],[1,7],[6,4],[7,0],[0,5]]
    4,[[2,0],[1,0],[3,1],[3,2],[1,3]]
)

print(r)