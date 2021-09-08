from functools import lru_cache
class Solution:
    def letterCasePermutation(self, s: str) -> [str]:
        @lru_cache(None)
        def isLowChar(cha):
            if ord('a')<=ord(cha) and ord(cha)<=ord('z'):
                return True
            else:
                return False
        @lru_cache(None)
        def isUpChar(cha):
            if ord('A')<=ord(cha) and ord(cha)<=ord('Z'):
                return True
            else:
                return False
        @lru_cache(None)
        def low2up(cha):
            return chr(ord(cha)^32)
        @lru_cache(None)
        def up2low(cha):
            return chr(ord(cha)|32)

        s = list(s)
        n = len(s)
        ans = set()

        def dfs(layer):
            # ans.add(''.join(s))

            if layer == n:
                ans.add(''.join(s))
                return 
            if isLowChar(s[layer]):
                dfs(layer+1)

                t = s[layer]
                s[layer] = low2up(s[layer])
                dfs(layer+1)
                s[layer] = t
            elif isUpChar(s[layer]):
                dfs(layer+1)

                t = s[layer]
                s[layer] = up2low(s[layer])
                dfs(layer+1)
                s[layer] = t
            else:
                dfs(layer+1)
        dfs(0)
        return list(ans)
s = Solution()
ya = s.letterCasePermutation(
    "a1b2"
)
print(ya)