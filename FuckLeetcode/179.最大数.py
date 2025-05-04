from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: 'List[int]') -> str:
        nums = [str(n) for n in nums]
        def cmp(a, b):
            if a == b:
                return 0
            
            ah = int(a + b)
            bh = int(b + a)
            if ah == bh:
                return 0
            return 1 if ah < bh else -1

        # nums = sorted(nums, key=cmp_to_key(cmp))
        nums.sort(key = cmp_to_key(cmp))
        print(nums)
        return str(int(''.join(nums)))

s = Solution()
r = s.largestNumber(
    #  [3,30,34,5,9]
    # [34323,3432]
    # [8308,8308,830]
    [0, 0]
)
print(r)