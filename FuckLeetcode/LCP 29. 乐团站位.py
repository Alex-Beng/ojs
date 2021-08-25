class Solution:
    def orchestraLayout(self, num: int, xPos: int, yPos: int) -> int:
        center = num//2 if num&1==1 else (num-1)/2

        layer_nums = (num+1)//2
        curr_layer = max(int(abs(xPos-center)),  int(abs(yPos-center)))
        curr_edge = curr_layer*2+1 if num&1 else (curr_layer+1)*2

        ans = 0
        ans = (curr_edge+num)*(layer_nums-curr_layer-1)*2
        
        curr_layer_ymin = curr_layer_xmin = layer_nums-curr_layer-1
        curr_layer_ymax = curr_layer_xmax = curr_layer_xmin+curr_edge-1

        if xPos==curr_layer_xmin and yPos>=curr_layer_ymin and yPos<curr_layer_ymax:
            ans += (yPos-curr_layer_ymin)+1
        elif yPos==curr_layer_ymax and xPos>=curr_layer_xmin and xPos<curr_layer_xmax:
            ans += curr_edge
            ans += (xPos-curr_layer_xmin)
        elif xPos==curr_layer_xmax and yPos<=curr_layer_ymax and yPos>curr_layer_ymin:
            ans += curr_edge
            ans += curr_edge-1
            ans += curr_layer_ymax-yPos
        else:
            ans += curr_edge
            ans += (curr_edge-1)*2
            ans += curr_layer_xmax-xPos
        ans = ans%9
        if ans==0:
            ans = 9
        return ans
s = Solution()
print(s.orchestraLayout(
    # 3,1,1
    4,2,1
    # 5, 2,2
# 392885312,
# 259226065,
# 336887518
))
# exit()
n = 4
for i in range(n):
    for j in range(n):
        t = s.orchestraLayout(n, i, j)
        print(t, end=' ')
    print()

        