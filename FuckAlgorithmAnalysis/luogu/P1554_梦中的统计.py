min, max = map(int, input().split())

nums = [str(i) for i in range(min, max+1)]
nums_count = [0]*10

for i in nums:
    for j in i:
        nums_count[int(j)] += 1
nums_count = [str(i) for i in nums_count]
print(' '.join(nums_count))