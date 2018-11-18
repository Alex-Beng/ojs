def bigger(s1, s2):
    if len(s1) > len(s2):
        return False
    elif len(s1) < len(s2):
        return True
    else:
        s1 = s1[::-1]
        s2 = s2[::-1]
        for i in range(len(s1)):
            if (s1[i] < s2[i]):
                return True
            else:
                return False
            

n = int(input())
ans = -1
max_n = ""
for i in range(n):
    t = input()
    
    # print(t>max_n)
    # print(t[::-1])
    if bigger(max_n, t):
        max_n = t[::-1]
        ans = i
print(i, max_n[::-1])
