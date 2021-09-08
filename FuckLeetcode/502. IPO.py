from heapq import *

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: [int], capital: [int]) -> int:
        n = len(profits)
        pro_cap = [(-profits[i], capital[i]) for i in range(n)]
        pro_cap.sort(key=lambda k: k[1], reverse=True)
        cap2idx = dict()
        for i in range(n-1, -1, -1):
            cap2idx[pro_cap[i][1]] = i

        heap = []
        tail_idx = n-1
        for i in range(k):
            # 直接遍历插入
            if tail_idx < 0:
                pass
            else:
                while tail_idx>=0 and pro_cap[tail_idx][1] <= w:
                    heappush(heap, pro_cap[tail_idx])
                    tail_idx -= 1
            if len(heap) == 0:
                break
            curr_pc = heappop(heap)
            w -= curr_pc[0]

        return w
        
        
s = Solution()
s.findMaximizedCapital(
    # 2, 0, [1,2,3], [0,1,1]
    1,0,[1,2,3],[1,1,2]
)