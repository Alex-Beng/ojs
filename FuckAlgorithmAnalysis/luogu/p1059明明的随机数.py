input()
num_list = list(map(int, input().split()))
num_set = set(num_list)
print(len(num_set))
for i in sorted(num_set):
    print(i, end=" ")