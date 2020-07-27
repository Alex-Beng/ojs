t = int(input())
for i in range(t):
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]
    
    # 统计num和出现次数
    num2times = dict()
    for t_num in nums:
        if t_num in num2times:
            num2times[t_num] += 1
        else:
            num2times[t_num] = 1
    # del num2times[max(num2times)]
    # print(max(num2times))
    all_2n = True
    for key in num2times:
        if (num2times[key] % 2 == 1):
            all_2n = False
    if (all_2n):
        print("NIUMEI")
    else:
        print("NIUNIU")
        # print(key, num2times[key])
            
