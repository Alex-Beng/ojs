#
# @lc app=leetcode.cn id=507 lang=python3
#
# [507] 完美数
#

# @lc code=start
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        ans = 1
        i = 2
        while i*i <= num:
            if num%i == 0:
                ans += i
                if num//i != i:
                    ans += num//i
            i += 1
        return ans == num if num!=1 else False
# @lc code=end

s = Solution()
s.checkPerfectNumber(
    1
)