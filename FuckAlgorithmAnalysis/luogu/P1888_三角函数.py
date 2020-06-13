def gcm(a, b):
    if a<b:
        pass
    else:
        a, b = b, a
    if b%a == 0:
        return a
    else:
        return gcm(b%a, a)
    


a, b, c = map(int, input().split())
down = max([a, b, c])
uper = min([a, b, c])

com = gcm(down, uper)
uper /= com
down /= com
print("%d/%d"%(uper, down))