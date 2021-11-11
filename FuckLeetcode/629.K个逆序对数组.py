import sys
sys.setrecursionlimit(1000000)

from functools import lru_cache
class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        @lru_cache(None)
        def pair(n: int, k: int) -> int:
            if n==0 and k==0:
                return 1
            if k<0 or n<=0:
                return 0
            return (pair(n, k-1)-pair(n-1, k-n)+pair(n-1, k))%int(1e9+7)
        return pair(n,k)
s = Solution()
r = s.kInversePairs(
    1000,1000
)
print(r)