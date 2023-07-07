import heapq

class Solution:
    def findCrossingTime(self, n: int, k: int, time: [[int]]) -> int:
        class worker:
            def __init__(self, idx, t):
                self.idx = idx
                self.t = t
                self.exp = t[0] + t[2]
            def __lt__(self, other):
                if self.exp > other.exp:
                    return True
                elif self.exp < other.exp:
                    return False
                else:
                    return self.idx > other.idx
        left_wait = []
        righ_wait = []
        left_work = []
        righ_work = []
        on_bridge = None

        for i in range(k):
            left_wait.append(worker(i, time[i]))
        heapq.heapify(left_wait)
        
        curr_time = 0
        ans = -1
        while n or len(righ_wait) or len(righ_work):
            # print(n,len(left_work), len(left_wait), len(righ_work), len(righ_wait))
            # print([i[0] for i in left_work])
            while len(righ_work) and curr_time >= righ_work[0][0]:
                _, wk = heapq.heappop(righ_work)
                heapq.heappush(righ_wait, wk)
            while len(left_work) and curr_time >= left_work[0][0]:
                _, wk = heapq.heappop(left_work)
                heapq.heappush(left_wait, wk)
            
            # right to left
            if len(righ_wait):
                wk = heapq.heappop(righ_wait)
                # print(f'wk{wk.idx} from right to left at {curr_time} -> {curr_time + wk.t[2]}')
                curr_time += wk.t[2]
                ans = max(ans, curr_time)
                heapq.heappush(left_work, (curr_time+wk.t[3], wk))
                # print(f'wk{wk.idx} put new from {curr_time} to {curr_time+wk.t[3]}')
            # left to right
            elif len(left_wait) and n:
                wk = heapq.heappop(left_wait)
                
                # print(f'wk{wk.idx} from left to right at {curr_time} -> {curr_time + wk.t[0]}')
                curr_time += wk.t[0]
                n -= 1
                heapq.heappush(righ_work, (curr_time+wk.t[1], wk))
                # print(f'wk{wk.idx} pick old from {curr_time} to {curr_time+wk.t[1]}')
            else:
                curr_time = left_work[0][0] if len(left_work) else curr_time+1
                curr_time = min(curr_time, righ_work[0][0]) if len(righ_work) else curr_time
                
            
        return ans
                
s = Solution()
r = s.findCrossingTime(
    # 1, 3,  [[1,1,2,1],[1,1,3,1],[1,1,4,1]]
    # 3, 2,  [[1,9,1,8],[10,10,10,10]]
    3, 2, [[3,2,4,1],[4,10,1,3]]
)
print(r)