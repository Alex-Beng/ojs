class pencil:
    def __init__(self, num, price):
        self.num = num
        self.price = price

    def how_much(self, pencil_num):
        ans = 0
        t_pencil_num = 0
        while t_pencil_num < pencil_num:
            t_pencil_num += self.num
            ans += self.price
        return ans


n = int(input())
ans = 0xffffffff

package_list = []
for i in range(3):
    t_num, t_price = map(int, input().split())
    package_list.append(pencil(t_num, t_price))
    if package_list[i].how_much(n) < ans:
        ans = package_list[i].how_much(n)
print(ans)
