import heapq

class Solution:
    def clearStars(self, s: str) -> str:
        qrq = []
        delIdxs = set()
        for i,c in enumerate(s):
            if c == '*':
                dc, di = heapq.heappop(qrq)
                delIdxs.add(-di)
            else:
                heapq.heappush(qrq, (c, -i))
        # print(delIdxs)
        return ''.join([s[i] for i in range(len(s)) if i not in delIdxs and s[i] != '*' ])

INPUT = [
    ("aaba*", )
]