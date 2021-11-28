from sortedcontainers import SortedList

class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        '''
        O(nlogn)
        '''
        n = len(nums)
        if n<3:
            return False

        left_min = nums[0]
        rights = SortedList(nums[2:])
        for j in range(1, n-1):
            if left_min < nums[j]:
                idx = rights.bisect_right(left_min)
                if idx!=len(rights) and rights[idx] < nums[j]:
                    return True
            left_min = min(left_min, nums[j])
            rights.remove(nums[j+1])
        return False

    def find132pattern(self, nums: List[int]) -> bool:
        '''
        O(n)
        单调栈
        '''
        n = len(nums)
        if n<3:
            return False
        sk = []
        second_big = float('-inf')
        for i in range(n-1, -1, -1):
            if nums[i] < second_big:
                return True
            while len(sk) and nums[i] > sk[-1]:
                second_big = max(second_big, sk[-1])
                del sk[-1]
            sk.append(nums[i])
        return False
