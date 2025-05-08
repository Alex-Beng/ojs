class Solution:
    
    def eula(self, n:int):
        if getattr(self, "DONE", None):
            return
        n = int(n + 666)
        prime = []
        visit = [False] * n
        primeNum = [0] * n
        for i in range(2, n):
            if not visit[i]:
                primeNum[i] = primeNum[i-1] + 1
                prime.append(i)
            else:
                primeNum[i] = primeNum[i-1]
                pass
            for j, p in enumerate(prime):
                if i * p >= n:
                    break
                visit[i * p] = True
                if i % p == 0:
                    break
        self.primeNum = primeNum
        self.DONE = True
        

    def countPrimes(self, n: int) -> int:
        self.eula(n)
        return self.primeNum[max(0, n-1)]

INPUT = [
    (10, ),
    (8, )
]
