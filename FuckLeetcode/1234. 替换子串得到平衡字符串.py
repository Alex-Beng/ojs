from functools import cache

class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        e = n // 4
        cnt = [0]*4 # out_cnt
        c2idx = {'Q': 0, 'W': 1, 'E':2, 'R': 3}
        for c in s:
            cnt[c2idx[c]] += 1
        
        end = 0
        ans = n
        for beg in range(0, n):
            while end < n and max(cnt) > e:
                cnt[c2idx[s[end]]] -= 1
                end += 1
            # 剪枝
            if max(cnt) > e:
                break
            ans = min(ans, end-beg)
            cnt[c2idx[s[beg]]] += 1
        return ans
                

s = Solution()
r = s.balancedString(
    "WWEQERQWQWWRWWERQWEQ"
)
print(r)

