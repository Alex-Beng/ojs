from math import *
distance = float(input())
t_sum_distance = 0.0
speed = 2.0
ans = 0

while t_sum_distance < distance:
    t_sum_distance += speed
    ans += 1 
    speed *= 0.98

print(ans)