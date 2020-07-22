def getMaxcommpisor(a,b):
    if a < b:
        a,b = b,a     
    while a%b != 0:
        a,b = b,a%b
    return b


in_ints = input().split()
in_ints = [int(i) for i in in_ints]
m = in_ints[0]
del in_ints[0]

sted = sorted(in_ints)

# m -> ways
m2ways = dict()

m2ways[sted[0]] = 1

if sted[1]%sted[0] != 0:
    m2ways[sted[1]] = 1
else:
    # m2ways[sted[1]] = sted[1]//sted[0]
    for i in range(sted[0], sted[1], sted[0]):
        m2ways[i] = 1
    m2ways[sted[1]] = 2

# if len(sted)>=3:
#     if (getMaxcommpisor(sted[2], sted[1]) == 1) and (getMaxcommpisor(sted[2], sted[0]))
# # print(m2ways)

for i in range(min(in_ints)+1, m+1):
    t_sum = 0
    for ci in in_ints:
        if i-ci >= 0 and (i-ci) in m2ways:
            t_sum += m2ways[i-ci]
        
    m2ways[i] = t_sum

print(m2ways[m])
