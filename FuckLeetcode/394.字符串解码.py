#
# @lc app=leetcode.cn id=394 lang=python3
#
# [394] 字符串解码
#

# @lc code=start
from functools import lru_cache

class Solution:
    def decodeString(self, s: str) -> str:
        @lru_cache(None)
        def is_num(c):
            return ord('0')<=ord(c)<=ord('9')
        
        def expr(s: str) -> (str, int):
            ans_s = ''
            n = len(s)
            i = 0
            while i<n:
                c = s[i]
                if c==']': # end of expr
                    return ans_s, i+1
                elif is_num(c): # beg of expr
                    tn = ''
                    while is_num(s[i]):
                        tn += s[i]
                        i += 1
                    ts,d_i = expr(s[i+1:])
                    
                    i += d_i
                    ans_s += ts*int(tn)
                else:
                    ans_s += c
                i += 1
            return ans_s,i

        return expr(s)[0]
                    
# @lc code=end

s = Solution()
r = s.decodeString(
    # "3[a]2[bc]"
    "3[a2[c]]"
)
print(r)