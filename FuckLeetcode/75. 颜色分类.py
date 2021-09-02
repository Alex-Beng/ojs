class Solution:
    def sortColors(self, nums: [int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        ones = 0
        twos = 0
        for t in nums:
            if t==1:
                ones+=1
            elif t==2:
                twos+=1
        # print(n-ones-twos, n, ones, twos)
        nums[::] = [0]*(n-ones-twos) + [1]*ones + [2]*twos
        # print(nums)
    def sortColors(self, nums: [int]) -> None:
        '''
        O(n) O(1)
        '''
        n = len(nums)

        zero_ptr = 0
        for i in range(n):
            if nums[i] == 0:
                # swap with zero ptr
                t = nums[zero_ptr]
                nums[zero_ptr] = nums[i]
                nums[i] = t
                zero_ptr += 1
        one_ptr = zero_ptr
        for i in range(zero_ptr, n):
            if nums[i] == 1:
                # swap with one ptr
                t = nums[one_ptr]
                nums[one_ptr] = nums[i]
                nums[i] = t
                one_ptr += 1
        print(nums[i])
                
s = Solution()
a = [1,1,1,2,2,2,0,0,0]
s.sortColors(a)
print(a)
