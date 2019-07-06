n = int(input())
nums = list(map(int, input().split()))
dp = [1]*len(nums)

for i in range(1, n):
    if nums[i]-nums[i-1] == 1:
        dp[i] = dp[i-1]+1
print(max(dp))