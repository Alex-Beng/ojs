input()
values = list(map(int, input().split()))
for i in range(len(values)):
    print(len([j for j in values[:i] if j < values[i]]), end = ' ')