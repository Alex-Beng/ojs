# 先按字典序排序从小到大join
# 然后解决'x'>'x0*'的问题
def GetMin(nums:list)->int:
    str_nums = [str(i) for i in nums]
    str_nums = sorted(str_nums)
    for i,ki in enumerate(str_nums):
        
        if len(ki) == 1:
            pass
        else:
            continue

        for j in range(i+1, len(str_nums)):
            kj = str_nums[j]
            if kj[0] == ki[0] and int(kj[1:]) == 0:
                t = str_nums[i]
                str_nums[i] = str_nums[j]
                str_nums[j] = i

    return int("".join(str_nums))

nums = list(input().split())
nums = [int(i) for i in nums]

print(GetMin(nums))