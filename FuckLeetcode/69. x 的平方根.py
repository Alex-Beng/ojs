class Solution:
    def mySqrt(self, x: int) -> int:
        ans = 0
        for n in range(x+1):
            if n*n <= x:
                ans = n
            else:
                break
        return ans
    def mySqrt(self, x: int) -> int:
        l = 0
        r = x
        while l<r:
            m = l + (r-l)//2
            if m*m > x:
                r = m
            else:
                l = m+1
        if l*l == x:
            return l
        elif l*l > x:
            return l-1
        else:
            return l
        # return l
s = Solution()
print(s.mySqrt(
    9
))