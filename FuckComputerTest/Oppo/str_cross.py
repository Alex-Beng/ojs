"""
aabcc
dbbca
aadbbcbcac


aabcc
dbbca
aadbbbaccc
"""

s1 = input()
s2 = input()
s3 = input()

# 搜索
can = False
def DFS():
    global s1, s2, s3, can
    # print('s1'+s1, 's2'+s2, 's3'+s3)
    if s1=="" and s2=="" and s3=="":
        can = True
        return

    # s1有马
    if s1!="" and s3!="" and s1[0] == s3[0]:
        t_head = s1[0]
        s1 = s1[1:]
        s3 = s3[1:]
        DFS()
        s1 = t_head+s1
        s3 = t_head+s3
    
    # s2有马
    if s2!="" and s3!="" and s2[0] == s3[0]:
        t_head = s2[0]
        s2 = s2[1:]
        s3 = s3[1:]
        DFS()
        s2 = t_head+s2
        s3 = t_head+s3

DFS()
if can:
    print("True")
else:
    print("False")
# out_True = 1

# while s3 != "":
#     s3_head = s3[0]
#     if s1!="" and s3_head == s1[0]:
#         s1 = s1[1:]
#         s3 = s3[1:]
#     elif s2!="" and s3_head == s2[0]:
#         s2 = s2[1:]
#         s3 = s3[1:]
#     else:
#         out_True = 0
#         break
#     print(s1)
#     print(s2)
#     print(s3)
#     print()

# if out_True:
#     print("True")
# else:
#     print("False")