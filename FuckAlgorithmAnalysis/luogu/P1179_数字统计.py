l, r = map(int, input().split())
ans = 0
for i in range(l, r+1):
    t_str = str(i)
    for j in t_str:
        if j=='2':
            ans += 1
print(ans)