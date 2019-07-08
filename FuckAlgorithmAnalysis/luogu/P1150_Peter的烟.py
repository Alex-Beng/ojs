n, k = map(int, input().split())
t_num = 0
ans = 0
while 1:
    if n == 0:
        break
    ans += n
    t = n
    n = (n+t_num)//k
    t_num = (t_num+t)%k
print(ans)