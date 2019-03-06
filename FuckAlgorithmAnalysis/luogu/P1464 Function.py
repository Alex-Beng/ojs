memorize = {}

def Function(a, b, c):
    if (a, b, c) in memorize.keys():
        return memorize[(a, b, c)]
    if a<=0 or b<=0 or c<=0:
        memorize[(a, b, c)] = 1
        return 1
    elif a>20 or b>20 or c>20:
        memorize[(a, b, c)] = Function(20, 20, 20)
        return memorize[(a, b, c)]
    elif a<b and b<c:
        memorize[(a, b, c)] = Function(a, b, c-1)+Function(a, b-1, c-1)-Function(a, b-1, c)
        return memorize[(a, b, c)]
    else:
        memorize[(a, b, c)] = Function(a-1, b, c)+Function(a-1, b-1, c)+Function(a-1, b, c-1) - Function(a-1, b-1, c-1)
        return memorize[(a, b, c)]


while (True):
    a, b, c = map(int, input().split())
    if a == -1 and b == -1 and c == -1:
        break
    print("w(%d, %d, %d) = %d"%(a, b, c, Function(a, b, c)))
    