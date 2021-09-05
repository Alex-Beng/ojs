class Solution:
    def twoSum(self, numbers: [int], target: int) -> [int]:
        n = len(numbers)
        l = 0
        r = n-1
        while l<r:
            ln = numbers[l]
            rn = numbers[r]
            if ln+rn > target:
                r -= 1
            elif ln+rn < target:
                l += 1
            else:
                return [l+1, r+1]