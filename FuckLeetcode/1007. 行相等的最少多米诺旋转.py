class Solution:
    def minDominoRotations(self, tops: 'List[int]', bottoms: 'List[int]') -> int:
        N = len(tops)
        num2times = {}
        for n in tops:
            num2times[n] = num2times.get(n, 0) + 1
        for n in bottoms:
            num2times[n] = num2times.get(n, 0) + 1
        
        maxn = sorted(range(1, 7), key=lambda k: num2times.get(k, 0))[-1]
        # print(maxn)
        opUp = 0
        for i in range(N):
            if tops[i] != maxn and bottoms[i] != maxn:
                opUp = -1
                break
            if tops[i] == maxn:
                pass
            else:
                opUp += 1
        
        opBot = 0
        for i in range(N):
            if tops[i] != maxn and bottoms[i] != maxn:
                opBot = -1
                break
            if bottoms[i] == maxn:
                pass
            else:
                opBot += 1
        # print(opUp, opBot)
        if opUp == -1 and opBot == -1:
            return -1
        if opUp == -1:
            return min(opBot, N-opBot)
        elif opBot == -1:
            return min(opUp, N-opUp)
        else:
            return min(min(opBot, N-opBot),  min(opUp, N-opUp))
    
s = Solution()
r = s.minDominoRotations(
    # [1,1,1,1], [2,2,2,1]
    [1,2,1,1,1,2,2,2], 
    [2,1,2,2,2,2,2,2]
)
print(r)