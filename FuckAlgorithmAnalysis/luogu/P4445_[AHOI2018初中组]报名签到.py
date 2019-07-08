n = int(input())
a = list(map(int, input().split()))
len = 0
for i in range(n-1):
    len += max(a[i], a[i+1])
print(len)