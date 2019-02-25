n = input()

nega_flag = 0
if n[0] == '-':
    nega_flag = 1
    n = "".join(list(n)[1:])

n =  "".join(reversed(list(n)))
if nega_flag:
    # n = "".join('-' + list(n))
    n_list = list(n)
    n_list.insert(0, '-')
    n = "".join(n_list)
print(int(n))