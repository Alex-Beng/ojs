n = int()
board = []
sum_solu = 0
need_print = 3

def put_able(row, col):
    if row<0 or row>=n or col<0 or col>=n:
        return False
    for i in range(row-1, -1, -1):
        if board[i][col] == 1:
            return False
    
    new_row = row - 1
    new_col = col - 1

    while new_row>=0 and new_col>=0:
        if board[new_row][new_col] == 1:
            return False
        new_row -= 1
        new_col -= 1
    
    new_row = row - 1
    new_col = col + 1

    while new_row<n and new_col<n:
        # print("here")
        if board[new_row][new_col] == 1:
            return False
        new_row -= 1
        new_col += 1
    
    return True


def dfs(layer):
    global sum_solu
    global need_print
    if layer == n:
        sum_solu += 1
        if need_print:
            need_print -= 1
            for i in board:
                print(i.index(1)+1, end = " ")
            print()
    else:
        for i in range(n):
            if put_able(layer, i):
                board[layer][i] = 1
                dfs(layer+1)
                board[layer][i] = 0
            else:
                continue


n = int(input())
for i in range(n):
    t = []
    for j in range(n):
        t.append(0)
    board.append(t)

# board[1][2] = 1
# print(board)
# print(put_able(2,1))
# for i in range(n):
#     print(put_able(1, i), end=" ")
dfs(0)
print(sum_solu)