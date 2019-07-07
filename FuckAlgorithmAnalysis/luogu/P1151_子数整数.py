k = int(input())
ans = ''
for i in range(10000, 30001):
    a = int(str(i)[:3])
    b = int(str(i)[1:4])
    c = int(str(i)[-3:])
    if a%k == 0 and b%k == 0 and c%k == 0:
        ans += "%d \n"%i
if ans:
    print(ans[:-2])
else:
    print("No")