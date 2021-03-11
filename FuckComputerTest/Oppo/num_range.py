"""
1,3 2,5
1,3 2,5 8,10 9,15
"""

ranges = input().split(" ")
ranges = [ [int(j) for j in i.split(',')] for i in ranges]

ans_ranges = []

def merge(rg1:list, rg2:list)->(bool, list):
    if rg1[1]>=rg2[0] and rg1[1]<=rg2[1]:
        return True, [min(rg1[0], rg2[0]), rg2[1]]
    elif rg1[0]>=rg2[0] and rg1[0]<=rg2[1]:
        return True, [rg2[0], max(rg1[1], rg2[1])]
    else:
        return False,[]

for sig_rg in ranges:
    if len(ans_ranges) == 0:
        ans_ranges.append(sig_rg)
        continue
    
    can_mg_rg = []
    for idx,t_rg in enumerate(ans_ranges):
        if merge(t_rg, sig_rg)[0]:
            # print("can merge", t_rg, sig_rg)
            can_mg_rg.append(t_rg)
            del ans_ranges[idx]
    
    for i in range(len(can_mg_rg)):
        # print("merging", can_mg_rg[i], sig_rg)
        _, can_mg_rg[i] = merge(can_mg_rg[i], sig_rg)
        # print("get", can_mg_rg[i])

    for t_rg in can_mg_rg:
        _, sig_rg = merge(sig_rg, t_rg)
    
    ans_ranges.append(sig_rg)
    

for rg in ans_ranges:
    print("%d,%d"%tuple(rg), end=" ")
print()