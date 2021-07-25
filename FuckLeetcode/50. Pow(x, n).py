class Solution:
    def myPow(self, x: float, n: int) -> float:
        ans = 1

        if n<=3 and n>=0:
            for i in range(n):
                ans *= x

            return ans
        elif n<0:
            t = self.myPow(x, -n)
            return 1/t
        else:
            t = self.myPow(x, n//2)
            if n%2 == 1:
                return t*t*x
            else:
                return t*t