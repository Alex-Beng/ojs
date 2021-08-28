n, m, p = map(int, input().split())
fa = [i for i in range(n+1)]
rank = [1 for i in range(n+1)]

def find(x):
    fa[x] = x if fa[x]==x else find(fa[x])
    return fa[x]

def merge(i, j):
    ifa = find(i)
    jfa = find(j)

    if rank[ifa]<=rank[jfa]:
        fa[ifa] = jfa
    else:
        fa[jfa] = ifa
    
    if rank[ifa]==rank[jfa] and ifa!=jfa:
        rank[jfa] += 1

for _ in range(m):
    mi, mj = map(int, input().split())
    merge(mi, mj)

for _ in range(p):
    qi, qj = map(int, input().split())
    if find(qi) == find(qj):
        print("Yes")
    else:
        print("No")