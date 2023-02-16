from typing import List, Tuple
from functools import cache

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        wd_lens = set([len(i) for i in wordDict])
        wds = set(wordDict)

        @cache
        def dfs(s: str) -> List[List[str]]:
            n = len(s)
            ans = []
            if n == 0:
                return tuple(tuple(['']), )
            for L in wd_lens:
                if L<=n and s[:L] in wds:
                    for tans in dfs(s[L:]):
                        ans.append([s[:L]] + list(tans))
            return tuple([tuple(t) for t in ans])
        ans = dfs(s)
        # print(ans)
        return [' '.join(t) for t in ans]
s = Solution()
r = s.wordBreak(
s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
)
print(r)