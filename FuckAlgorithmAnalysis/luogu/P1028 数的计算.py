dp = [0]
dp.append(1)
dp.append(2)

n = int(input())
for i in range(3,n+1):
    # dp_i = i//2
    dp_i = 1
    for j in range(1, i//2+1):
        dp_i += dp[j]
    dp.append(dp_i)
print(dp[n])