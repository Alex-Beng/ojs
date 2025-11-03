class Solution:
    def minCost(self, colors: str, neededTime: 'List[int]') -> int:
        N = len(colors)
        sums = [0] * (N)
        maxs = [n for n in neededTime]
        res = 0

        for i in range(N):
            # print(res, sums, maxs)
            n = neededTime[i]
            if not i:
                sums[i] = n
                maxs[i] = n
                continue
            cc = colors[i]
            pc = colors[i-1]
            if cc == pc:
                sums[i] = sums[i-1] + n
                if n >= maxs[i-1]:
                    maxs[i] = n
                else:
                    maxs[i] = maxs[i-1]

            else:
                sums[i] = n
                maxs[i] = n


            if cc != pc:
                res += (sums[i-1] - maxs[i-1])
            elif i == N-1:
                res += sums[i] - maxs[i]

            
        # print(res, sums, maxs)
        return res

INPUT = [
    ("abaac", [1,2,3,4,5]),
    ("abc", [1,2,3]),
    ("aabaa", [1,2,3,4,1]),
]