class Solution:
    def fib(self, n: int) -> int:
        a = 0
        b = 1
        c = 1
        for _ in range(2, n+1):
            c = a+b
            a, b = b, c
        return c%(1000000007) if n!=0 else 0
        
s = Solution()
while True:
    n = int(input())
    print(s.fib(n))