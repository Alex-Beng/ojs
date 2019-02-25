a, b, c = map(int, input().split())

digits = [0]*3

def check_ans():
    return

flag = 1
def dfs(layer):
    global flag
    if layer == 3:
        t1 = int("".join([str(i) for i in digits]))
        t2 = t1*b//a
        t3 = t1*c//a
        t_all = str(t1)+str(t2)+str(t3)
        if len(t_all) > 9:
            return
        for i in range(1, 10):
            if not str(i) in t_all:
                return
        print(t1, t2, t3)
        flag = 0
    else:
        for i in range(1, 10):
            digits[layer] = i
            dfs(layer+1)

dfs(0)
if flag:
    print("No!!!")