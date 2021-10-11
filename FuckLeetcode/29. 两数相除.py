class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        ans = dividend//divisor if dividend*divisor>0 else -(abs(dividend)//abs(divisor))
        ans = max(ans, -2**31)
        ans = min(ans, 2**31-1)
        return ans