n = int(input())
rects = []
for i in range(n):
    a, b, c, d = map(int, input().split())
    rects.append((a,b,c,d))
x, y = map(int, input().split())

def inside(x, y, i):
    if x >= i[0] and x <= i[0]+i[2] and y >= i[1] and y <= i[1]+i[3]:
        # print("%d, %d is inside %d"%(x, y, i[0]))
        return True
    return False

count = -1

for i in range(len(rects)):
    if inside(x, y, rects[i]):
        count = i

if count == -1:
    print(-1)
else:
    print(count+1)