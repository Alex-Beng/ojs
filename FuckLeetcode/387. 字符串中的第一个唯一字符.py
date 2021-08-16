from collections import Counter

class Solution:
    def firstUniqChar(self, s: str) -> int:
        cha2num = Counter(s)
        cha2idx = dict()
        for idx,cha in enumerate(s):
            cha2idx[cha] = idx
        idx = len(s)
        for k in cha2num:
            if cha2num[k]==1 and cha2idx[k]<idx:
                idx = cha2idx[k]
        return -1 if idx==len(s) else idx