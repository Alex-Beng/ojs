num_list = list(range(1,11))
used = [False]*9

def dfs(layer):
    if layer == 9:
        
        num_str_list = [str(i) for i in num_list]
        t_str = "".join(num_str_list)
        num_1 = int(t_str[0:3])
        num_2 = int(t_str[3:6])
        num_3 = int(t_str[6:9])
        if num_1*2 == num_2 and num_1*3 == num_3:
            print(num_1, num_2, num_3)
    else:
        for i in range(9):
            if not used[i]:
                if layer == 6 and i <= 3: # 剪枝
                    continue
                elif layer == 0 and i>= 4:
                    continue
                num_list[layer] = i+1
                used[i] = True
                
                dfs(layer+1)
                used[i] = False   
            
dfs(0)