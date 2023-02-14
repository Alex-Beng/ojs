from typing import List

class Solution:
    # O(nlogn)
    def longestWPI(self, hours: List[int]) -> int:
        n = len(hours)
        hours = [1 if i > 8 else -1 for i in hours]
        pre_sum = [0] * (n+1)
        min_ps = [n+7] * (n+1)
        min_ps[0] = 0
        for i in range(1, n+1):
            pre_sum[i] = pre_sum[i-1] + hours[i-1]
            min_ps[i] = min(min_ps[i-1], pre_sum[i])

        ans = 0
        # [beg, end)
        for end in range(n, 0, -1):
            # 简单剪枝
            if end <= ans:
                break
            if pre_sum[end] > min_ps[end]:
                # 在min_ps [0, end) 上二分，寻找最小的 j 使得 min_ps[j] < pre_sum[end]
                left, righ = 0, end-1
                while left <= righ:
                    mid = (left + righ) // 2
                    mid_val = min_ps[mid]
                    if mid_val >= pre_sum[end]:
                        left = mid+1
                    elif mid_val < pre_sum[end]:
                        righ = mid-1
                # left 为最小的j
                ans = max(ans, end-left)

        return ans
    # O(n) 单调栈
    def longestWPI(self, hours: List[int]) -> int:
        n = len(hours)
        hours = [1 if i>8 else -1 for i in hours]
        pre_sum = [0] * (n+1)
        de_sk = [0]
        for i in range(1, n+1):
            pre_sum[i] = pre_sum[i-1] + hours[i-1]
            if len(de_sk) == 0 or pre_sum[de_sk[-1]] >  pre_sum[i]:
                de_sk.append(i)

        ans = 0
        for end in range(n, 0, -1):
            while len(de_sk) and pre_sum[end] > pre_sum[de_sk[-1]]:
                ans = max(ans, end-de_sk[-1])
                del de_sk[-1]
        return ans
s = Solution()
r = s.longestWPI(
     [9,9,6,0,6,6,9]
    # [6,6,6]
)
print(r)