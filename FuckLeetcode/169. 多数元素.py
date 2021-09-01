class Solution:
    def majorityElement(self, nums: [int]) -> int:
        n = len(nums)

        mole_num = nums[0]
        mole_cnt = 1
        
        for i in range(1, n):
            num = nums[i]
            if mole_cnt == 0:
                mole_cnt += 1
                mole_num = num
            else:
                if num != mole_num:
                    mole_cnt -= 1
                else:
                    mole_cnt += 1
        return mole_num
s = Solution()
print(s.majorityElement(
    [1,1,1,3,4,8,8,8,8,1,1,1,1]
))
        