nums = []
for i in range(10):
    nums.append(int(input()))

ten = [0]*42

for i in range(10):
    ten[nums[i]%42] = 1

print(sum(ten))