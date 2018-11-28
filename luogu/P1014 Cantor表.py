from math import *
n = int(input())

status_flag = 0
counter = 1
upper = 1
downer = 1

def judge(counter):
    if counter == n:
        return True
    else:
        return False

for i in range(n-1):
    if status_flag == 0: # to right
        downer += 1
        status_flag = 1
    elif status_flag == 1:
        upper += 1
        downer -= 1
        if downer == 1:
            status_flag = 2
    elif status_flag == 2:
        upper += 1
        status_flag = 3
    elif status_flag == 3:
        upper -= 1
        downer += 1
        if upper == 1:
            status_flag = 0

    # print("%d/%d"%(upper, downer))

print("%d/%d"%(upper, downer))