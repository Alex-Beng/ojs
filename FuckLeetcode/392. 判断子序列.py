class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        t_cha2idxes = dict()

        for idx,cha in enumerate(t):
            if cha in t_cha2idxes:
                t_cha2idxes[cha].append(idx)
            else:
                t_cha2idxes[cha] = [idx]
        
        curr_idx = -1
        for cha in s:
            if cha in t_cha2idxes:
                # 二分查找找出比curr_idx 大的
                idxes = t_cha2idxes[cha]
                L = 0
                R = len(idxes)
                while L<R:
                    m = L+(R-L)//2
                    if idxes[m] < curr_idx:
                        L = m+1
                    else:
                        R = m
                
                if L >= len(idxes):
                    return False
                curr_idx = idxes[L]+1
            else:
                return False
        return True
s = Solution()
print(s.isSubsequence(
"ac",
"ahbgdc"
))