n = int(input())
ans = -1
ans_index = -1
for i in range(n):
    t = int(input())
    if t > ans:
        ans = t
        ans_index = i
print(ans_index+1)
print(ans)