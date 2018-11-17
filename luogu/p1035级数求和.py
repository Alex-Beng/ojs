k = int(input())
dp = [1]
dp_index = 1
sum_of_dp = 1
while sum_of_dp <= k:
    dp.append(1/(dp_index+1))
    sum_of_dp += 1/(dp_index+1)
    dp_index += 1
print(dp_index)