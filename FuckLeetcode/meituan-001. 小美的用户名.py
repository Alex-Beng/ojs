T = int(input())
for _ in range(T):
    name = input()
    fcha = ord(name[0])
    if ord('A')<=fcha and fcha<=ord('Z') or ord('a')<=fcha and fcha<=ord('z'):
        pass
    else:
        print("Wrong")
        continue

    valid = True
    has_cha = has_num = 0
    for c in name:
        fcha = ord(c)
        if ord('A')<=fcha and fcha<=ord('Z') or ord('a')<=fcha and fcha<=ord('z'):
            has_cha = 1
        elif ord('0')<=fcha and fcha<=ord('9'):
            has_num = 1
        else:
            valid = False
    if not valid or has_cha+has_num<2:
        print("Wrong")
        continue
    print("Accept")

