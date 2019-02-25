n = int(input())

nums = list(map(int, input().split()))
dp = [-1]*n
ans = -0xffffff

dp[0] = nums[0]
for i in range(1, n):
    dp[i] =  max(nums[i], dp[i-1]+nums[i])
    if dp[i] > ans:
        ans = dp[i]
print(ans)