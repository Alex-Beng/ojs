num2times = {}

def dfs(a, b, c, t_sum, layer):
    if layer==0:
        for i in range(1, a+1):
            dfs(a, b, c, t_sum+i, layer+1)
    elif layer==1:
        for i in range(1, b+1):
            dfs(a, b, c, t_sum+i, layer+1)
    elif layer==2:
        for i in range(1, c+1):
            if t_sum+i in num2times:
                num2times[t_sum+i] += 1
            else:
                num2times[t_sum+i] = 1

if __name__ == "__main__":
    a, b, c = map(int, input().split())
    dfs(a, b, c, 0, 0)
    keys = sorted(num2times.items(), key=lambda item:item[1], reverse=True)
    print(keys[0][0])