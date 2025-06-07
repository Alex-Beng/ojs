from typing import List
from math import log10, ceil

class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        # L = ceil(log10(n))

        def dfs(digits, res):
            # print(digits, L)
            if digits > n:
                return
            if 1 <= digits and digits <= n:
                res.append(digits)
            for i in range(10):
                dfs(digits*10+i, res)
        
        res = []
        for i in range(1, 10):
            dfs(i, res)
        return res
INPUT = [
    # (13, ),
    (1, )
]