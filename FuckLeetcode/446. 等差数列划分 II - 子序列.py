from collections import defaultdict
class Solution:
    def numberOfArithmeticSlices(self, nums) -> int:
        n = len(nums)
        dp = [dict() for i in range(n)]

        ans = 0
        for i in range(n):
            for j in range(i):
                t_delta = nums[i]-nums[j]
                if t_delta in dp[j]:
                    ans += dp[j][t_delta]
                    if t_delta in dp[i]:
                        dp[i][t_delta] += dp[j][t_delta]+1
                    else:
                        dp[i][t_delta] = dp[j][t_delta]+1
                else:
                    if t_delta in dp[i]:
                        dp[i][t_delta] += 1
                    else:
                        dp[i][t_delta] = 1
                # print(dp)
        # for i in range(n):
        #     # print(dp[i].keys())
        #     print(i, dp[i].keys(), dp[i].values())
        # print(ans)
        return ans
# class Solution:
#     def numberOfArithmeticSlices(self, nums) -> int:
#         ans = 0
#         f = [defaultdict(int) for _ in nums]
#         for i, x in enumerate(nums):
#             for j in range(i):
#                 d = x - nums[j]
#                 cnt = f[j][d]
#                 ans += cnt
#                 f[i][d] += cnt + 1
#         return ans
s = Solution()
print(s.numberOfArithmeticSlices(
    # [2,2,3,4]
    #  [2,4,6,8,10]
    [7,7,7,7,7]
))