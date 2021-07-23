class Solution:
    def tribonacci(self, n: int) -> int:
        tibs = [0]*(n+3)
        tibs[1] = 1
        tibs[2] = 1
        for i in range(3, n+3):
            tibs[i] = tibs[i-1] + tibs[i-2] + tibs[i-3]
        return tibs[n]
