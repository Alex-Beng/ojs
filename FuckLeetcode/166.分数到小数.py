#
# @lc app=leetcode.cn id=166 lang=python3
#
# [166] 分数到小数
#

# @lc code=start
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
            
        sign = "" 
        if numerator*denominator < 0:
            sign = "-"
            numerator = abs(numerator)
            denominator = abs(denominator)


        factor = 1
        cnt = 0
        been = dict()
        ans = []
        circle = False
        while numerator != 0:
            curr_res = numerator//denominator
            ans.append(str(curr_res))
            if (numerator,denominator, str(curr_res)) in been:
                circle = True
                break

            if cnt!=0:
                been[(numerator,denominator, str(curr_res))] = cnt


            numerator %= denominator
            numerator *= 10

            factor *= 10
            cnt += 1
        
        # 没有小数
        if len(ans) == 1:
            return f'{sign}{ans[0]}'
        # 循环小数
        if circle:
            ya = (numerator,denominator, str(curr_res))
            return f'{sign}{ans[0]}.{"".join(ans[1:been[ya]])}({"".join(ans[been[ya]:len(ans)-1])})'    
        # 不是就瞎搞8
        else:
            return f'{sign}{ans[0]}.{"".join(ans[1:])}'

# @lc code=end

s = Solution()
r = s.fractionToDecimal(
    # 1,333
    # 0,3
    -50, 8

)
print(r)