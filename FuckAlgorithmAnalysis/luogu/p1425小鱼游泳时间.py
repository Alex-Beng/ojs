begin_hour, begin_min, end_hour, end_min = map(int, input().split())
diff_in_min = (60*end_hour+end_min) - (60*begin_hour+begin_min)
print(diff_in_min//60, diff_in_min % 60)