n = int(input())
ans = 0
t = 0
for i in range(n):
    t1, t2 = map(int, input().split())
    t = t+t1+t2 - 8
    ans += t
print(ans)