from queue import Queue

class Solution:
    def numWays(self, n: int, relation: [[int]], k: int) -> int:
        able = [[0]*n for _ in range(n)]
        for f,t in relation:
            able[f][t] = 1
        q = Queue()
        q.put([0])
        ans = 0
        while not q.empty():
            path = q.get()
            f = path[-1]
            if len(path) == k+1:
                if f == n-1:
                    ans += 1
                continue

            for t,ab in enumerate(able[f]):
                if ab:
                    q.put(path+[t])
        return ans


