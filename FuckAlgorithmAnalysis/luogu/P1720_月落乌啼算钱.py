n = int(input())

fs = [1]*n
for i in range(2, n):
    fs[i] = fs[i-1]+fs[i-2]
if n != 0:
    print("%d.00"%fs[-1])
else:
    print("0.00")