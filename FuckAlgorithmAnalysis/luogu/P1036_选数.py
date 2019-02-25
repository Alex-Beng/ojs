n, k = map(int, input().split())
digit = [0]*n

nums = list(map(int, input().split()))

def IsPrime(num):
    for i in range(2, num):
        if num%i == 0:
            return False
    return True

# to genearte all the n bits binary num
ans = 0
def dfs(layer):
    global ans
    if layer == n:
        # print(digit)
        if sum(digit) == k:
            t_sum = 0
            for i in range(n):
                if digit[i]:
                    t_sum += nums[i]
            if IsPrime(t_sum):
                ans += 1
    else:
        dfs(layer+1)
        digit[layer] = 1
        dfs(layer+1)
        digit[layer] = 0
dfs(0)
print(ans)