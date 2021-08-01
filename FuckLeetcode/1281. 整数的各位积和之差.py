class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        def get_digit_sum(n):
            if n<10:
                return n
            else:
                return (n%10) + get_digit_sum(n//10)
        def get_digit_pro(n):
            if n<10:
                return n
            else:
                return (n%10) * get_digit_pro(n//10)
        return -get_digit_sum(n)+get_digit_pro(n)
        
s = Solution()
s.subtractProductAndSum(234)