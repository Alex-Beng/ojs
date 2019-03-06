n, power = map(int, input().split())
chair_height, taotao_height = map(int, input().split())
apples = []

for i in range(n):
    apples.append(tuple(map(int, input().split())))

apples.sort(key=lambda apple: apple[1], reverse=False, fun=2)
# print(apples)
ans = 0
for i in apples:
    if power-i[1]>=0 and chair_height+taotao_height >= i[0]:
        power -= i[1]
        ans += 1
print(ans)

# 这个不可以搜索鸭 弟弟...n 
# ans = 0
# t_sum_apples = 0
# def dfs(layer):
#     global ans
#     global power
#     global t_sum_apples
#     if layer == n:
#         if t_sum_apples > ans:
#             ans = t_sum_apples
#     else:
#         dfs(layer+1)
#         if chair_height+taotao_height > apples[layer][0] and power-apples[layer][1] >= 0:
#             # power -= apples_need_power[layer]
#             power -= apples[layer][1]
#             t_sum_apples += 1
#             dfs(layer+1)
#             # power += apples_need_power[layer]
#             power += apples[layer][1]
#             t_sum_apples -= 1

# dfs(0)
# print(ans)