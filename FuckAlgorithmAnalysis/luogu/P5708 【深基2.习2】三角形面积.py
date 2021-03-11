def tri_area(a, b, c):
    from math import sqrt
    p = (a+b+c)/2.0
    return sqrt(p*(p-a)*(p-b)*(p-c))

a,b,c = map(float, input().split())
print("%.1f"%tri_area(a, b, c))