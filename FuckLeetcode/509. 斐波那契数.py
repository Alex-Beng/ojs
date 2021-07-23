class Solution:
    
    def fib(self, n: int) -> int:
        fibs = [0]*(n+2)
        fibs[1] = 1
        for i in range(2, n+2):
            fibs[i] = fibs[i-1] + fibs[i-2]
        return fibs[n]
