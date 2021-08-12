class Solution:
    def countDigitOne(self, n: int) -> int:
        ten_power = 1
        ans = 0
        while n//ten_power > 0:
            prev = n//(ten_power*10)
            curr = (n//ten_power)%10
            last = n%(ten_power)
            # print(prev, curr, last)
            ans += prev * ten_power
            # print(ans)
            if curr == 0:
                pass
            elif curr == 1:
                ans += (last+1)
            else:
                ans += (ten_power)
            # print(ans)
            # print(ans, ten_power)
            ten_power *= 10
        return ans
s = Solution()
print(s.countDigitOne(
    13
))