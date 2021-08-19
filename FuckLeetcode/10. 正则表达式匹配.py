class Solution:

    def isMatch(self, s: str, p: str) -> bool:
        # print(s, p)
        pn = len(p)
        sn = len(s)
        if pn==0:
            return sn==0
        else:
            if pn<2 or pn>=2 and p[1]!='*':
                if sn!=0 and (s[0]==p[0] or p[0]=='.'):
                    return self.isMatch(s[1:], p[1:])
                else:
                    return False
            else:
                t_ans = False
                t_ans |= self.isMatch(s, p[2:]) # 0's cha
                for idx in range(0, sn):
                    if s[idx]==p[0] or p[0]=='.':
                        t_ans |= self.isMatch(s[idx+1:], p[2:])
                    else:
                        break
                return t_ans
s = Solution()
print(s.isMatch(
    # 'ab', '.*c'
    'a', 'ab*'
    # 'aab', 'c*a*'
    # 'mississippi', 'mis*is*p*.'
))

                        
