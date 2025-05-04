class Solution:
    def numSubarrayBoundedMax(self, nums: 'List[int]', left: int, right: int) -> int:
        N = len(nums)
        lastL = -1
        lastR = -1
        i = 0
        res = 0
        while i < N:
            if nums[i] > right:
                lastR = i
            elif nums[i] < left:
                if lastL > lastR:
                    res += lastL-lastR
            else:
                res += i - lastR
                lastL = i
            i += 1
        return res
INPUT = [
    ([2,1,4,3], 2, 3),
    ([2,9,2,5,6], 2, 8),
    ([73,55,36,5,55,14,9,7,72,52], 32, 69)
]

