class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        N = len(dominoes)
        if N <= 1:
            return dominoes

        Lpulse = [0] * N if dominoes[-1] != 'L' else [1] * N
        Rpulse = [0] * N if dominoes[0] != 'R' else [1] * N
        for i in range(1, N):
            c = dominoes[i]
            if c == 'R':
                Rpulse[i] = 1
            elif c == 'L':
                Rpulse[i] = 0
            else:
                Rpulse[i] = Rpulse[i-1] + 1 if Rpulse[i-1] else 0
        for i in range(N-2, -1, -1):
            c = dominoes[i]
            if c == 'R':
                Lpulse[i] = 0
            elif c == 'L':
                Lpulse[i] = 1
            else:
                Lpulse[i] = Lpulse[i+1] + 1 if Lpulse[i+1] else 0
        # print(Lpulse)
        # print(Rpulse)
        res = []
        for i in range(N):
            c = dominoes[i]
            if c == 'L' or c == 'R':
                res.append(c)
            else:
                if Lpulse[i] == Rpulse[i]:
                    res.append('.')
                else:
                    if Lpulse[i] < Rpulse[i]:
                        newC = 'L' if Lpulse[i] != 0 else 'R'
                    elif Lpulse[i] > Rpulse[i]:
                        newC = 'R' if Rpulse[i] != 0 else 'L'
                    else:
                        newC =  '.'
                    res.append(newC)

        return ''.join(res)
s = Solution()
i = "RR.L"
print(i)
r = s.pushDominoes(
    i
)
print(r)
print()

i = ".L.R...LR..L.."
print(i)
r = s.pushDominoes(
    i
)
print(r)
print("LL.RR.LLRRLL..")

i = "R."
print(i)
r = s.pushDominoes(
    i
)
print(r)