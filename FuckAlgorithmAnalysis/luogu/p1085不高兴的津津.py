time_lists = []
most_hours = -1
for i in range(7):
    time_lists.append(sum(map(int, input().split())))
    if time_lists[i] > 8:
        most_hours = max(most_hours, time_lists[i])

flag = True
for i in range(7):
    if time_lists[i] == most_hours and most_hours != -1:
        print(i+1)
        flag = False
        break

if flag:
    print(0)
