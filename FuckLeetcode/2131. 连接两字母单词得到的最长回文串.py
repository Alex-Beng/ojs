from typing import List

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        TT2Num = {}
        AB2Num = {}
        pairs = {}
        for wd in words:
            if wd[0] == wd[1]:
                TT2Num[wd] = TT2Num.get(wd, 0) + 1
            rwd = wd[::-1]
            pwd = min(wd) + max(wd)
            if rwd in AB2Num and AB2Num[rwd] > 0:
                pairs[pwd] = pairs.get(pwd, 0) + 1
                AB2Num[rwd] -= 1
            else:
                AB2Num[wd] = AB2Num.get(wd, 0) + 1
        
        if TT2Num and (oddKeys:=[k for k in TT2Num.keys() if TT2Num[k]&1]):
            # del top odd tt
            topTT = max(oddKeys, key=lambda k: TT2Num[k])
            topTT in pairs and pairs.pop(topTT)

            p2 = pairs and sum(pairs.values()) or 0
            return TT2Num[topTT] * 2 + p2 * 4
        else:
            p2 = pairs and sum(pairs.values()) or 0

            return p2 * 4
            pass
            
        p1 = TT2Num and max(TT2Num.values()) or 0
        p2 = pairs and sum(pairs.values()) or 0

        return (p1 * 2 + p2 * 4)
INPUT = [
    # (["lc","cl","gg"], ),
    # (["ab","ty","yt","lc","cl","ab"], ),
    # (["dd","aa","bb","dd","aa","dd","bb","dd","aa","cc","bb","cc","dd","cc"], ),
    # (["mm","mm","yb","by","bb","bm","ym","mb","yb","by","mb","mb","bb","yb","by","bb","yb","my","mb","ym"], )
    (["nn","nn","hg","gn","nn","hh","gh","nn","nh","nh"],)
]