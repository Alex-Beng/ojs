import heapq

class Solution:
    def kWeakestRows(self, mat, k: int):
        row = len(mat)
        col = len(mat[0])

        ans = []
        for i,r_line in enumerate(mat):
            l = 0
            r = col
            while l < r:
                m = l + (r-l)//2
                if r_line[m]<1:
                    r = m
                else:
                    l = m+1 
            # ans.append((l, i)) #OR
            heapq.heappush(ans, (l, i))
        
        # s_ans = sorted(list(range(row)), key=lambda k: ans[k]) #OR
        s_ans = [0]*k
        for i in range(k):
            s_ans[i] = heapq.heappop(ans)[1]
        # print(s_ans)
        return s_ans

s = Solution()
s.kWeakestRows(
    [[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
 3
)