num = list(map(int, input().split()))
del num[-1]
for i in num[::-1]:
    print(i, end=' ')