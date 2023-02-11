from typing import List

class Solution:
    def fillCups(self, amount: List[int]) -> int:
        # 我是傻逼，以供瞻仰
        res = 0
        while sum(amount):
            sum23 = sum(amount) - max(amount)
            bst = max(amount)
            if bst-1 <= sum23 < bst+1:
                res += bst
                break
            elif sum23 < bst-1:
                res += bst
                break
            elif sum23 == bst+1:
                res += (bst+1)
                break
            else:
                # 找到最大和次大的减1
                amount.sort()
                # print(amount)
                amount[2] -= 1
                amount[1] -= 1
                res += 1
        return res
    def fillCups(self, amount: List[int]) -> int:
        amount.sort()
        sumall = sum(amount)
        bst = amount[-1]
        sum23 = sumall - bst

        if sum23 <= bst:
            return bst
        else:
            return bst + (sum23-bst+1)//2

s = Solution()
r = s.fillCups(
    [5,4,4]
)
print(r)