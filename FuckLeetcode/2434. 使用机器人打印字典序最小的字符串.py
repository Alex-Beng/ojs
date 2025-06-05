from collections import Counter

class Solution:
    def robotWithString(self, s: str) -> str:
        c2t = Counter(s)
        
        sk = []
        i = 0
        N = len(s)
        res = []

        currC = 'a'
        for c in s:
            sk.append(c)
            c2t[c] -= 1
            
            while currC != 'z' and c2t[currC] == 0:
                currC = chr(ord(currC) + 1)
            while sk and sk[-1] <= currC:
                res.append(sk.pop())
                        
        # print(res, sk)
        res += sk[::-1]
        return "".join(res)
INPUT = [
    ("zza", ),
    # ("bac", ),
    # ("bdda", ),
    # ("vzhofnpo", ),
    ("bydizfve", )
]