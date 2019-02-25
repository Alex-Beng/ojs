heights = list(map(int, input().split()))
tao_height = int(input()) + 30
ans = 0
for i in heights:
    if tao_height >= i:
        ans += 1
print(ans)