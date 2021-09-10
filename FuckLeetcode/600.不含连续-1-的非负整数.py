#
# @lc app=leetcode.cn id=600 lang=python3
#
# [600] 不含连续1的非负整数
#

# @lc code=start
class Solution:
    def findIntegers(self, n: int) -> int:
        def nums(blen):
            dp = [[1]*2 for i in range(blen+1)]
            for i in range(2, blen+1):
                dp[i][0] = sum(dp[i-1])
                dp[i][1] = dp[i-1][0]
            
            return sum(dp[blen]) if blen!=0 else 1
        one_pos = []
        cnt = 0
        while n!=0:
            if n&1:
                one_pos.append(cnt)
            n >>= 1
            cnt += 1
        one_pos = one_pos[::-1]
        ans = nums(one_pos[0])
        n_valid = True
        for i in range(1, len(one_pos)):
            if one_pos[i-1]-one_pos[i] == 1:
                # add and break
                ans += nums(one_pos[i])
                n_valid = False
                break
            else:
                # add and continue
                ans += nums(one_pos[i])
        if n_valid:
            ans += 1
        return ans


s = Solution()
res = s.findIntegers(int(1e100))
print(res)
# @lc code=end

