status = 0 
# 0 for begin, 1 for partA, 2 for partB, 3 for mergeconfig, 4 for end
a_keys = []
b_keys = []

# no->data
# data:dict()
#   key->value
a_no2data = dict()
b_no2data = dict()
a_cols = []
b_cols = []
merge_map = dict()
while True:
    line = input()
    
    if line == "partA.csv:":
        status = 1
        # get keys
        line = input()
        a_keys = line.split(',')
        continue
    elif line == "partB.csv:":
        status = 2
        line = input()
        b_keys = line.split(',')
        continue
    elif line == "mergeconfig.csv:":
        status = 3
        line = input()
        continue
    elif line == "//EOF":
        status = 4
    
    # skip empty line
    if line == "":
        continue


    values = line.split(',')
    if status == 1:
        a_cols.append(dict(zip(a_keys, values)))
        a_no2data[a_cols[-1]['NO']] = len(a_cols)-1
    elif status == 2:
        b_cols.append(dict(zip(b_keys, values)))
        b_no2data[b_cols[-1]['NO']] = len(b_cols)-1
    elif status == 3:
        merge_map[values[1]] = values[0]
        merge_map[values[0]] = values[1]
    elif status == 4:
        break
# print(a_no2data)
# merge keys
merge_keys = [i for i in a_keys]
for key in b_keys:
    key_in_a = False

    if key in a_keys:
        key_in_a = True
    if key in merge_map:
        if merge_map[key] in a_keys:
            key_in_a = True
        
    if key_in_a:
        continue
    else:
        merge_keys.append(key)

print("partAB.csv:")
print(','.join(merge_keys))

for col in a_cols:
    # NO = col['NO']
    
    # find no in b
    # NO_in_b = False
    # if NO in b_no2data:
    #     NO_in_b = True
    
    out_line = []
    for key in merge_keys:
        if key in a_keys:
            out_line.append(col[key])
        else:
            out_line.append("")
    print(",".join(out_line))
    # print(no)


for col in b_cols:
    out_line = []
    for key in merge_keys:
        if key in b_keys:
            out_line.append(col[key])
        elif key in merge_map and merge_map[key] in b_keys:
            out_line.append(col[merge_map[key]])
            
    print(",".join(out_line))
            