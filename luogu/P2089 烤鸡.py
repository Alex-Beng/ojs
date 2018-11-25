n = int(input())
ans = 0

sln = [0]*10
def dfs(layer, flag):
    global n
    global ans
    if layer == 10:
        if n == 0:
            ans += 1
            if (flag):
                for i in sln:
                    print(i, end=" ")
                print()
    else:
        for i in range(1, 4):
            if (n-i >= 0):
                n -= i
                sln[layer] = i
                dfs(layer+1, flag)
                n += i
                sln[layer] = 0

dfs(0, False)
print(ans)
dfs(0, True)