class Solution:
    def majorityElement(self, nums) -> int:
        mole_num = nums[0]
        mole_cnt = 1
        for num in nums[1:]:
                
            if mole_num == num:
                mole_cnt += 1
            else:
                mole_cnt -= 1
                if mole_cnt == 0:
                    mole_num = num
                    mole_cnt = 1
        cnt = 0
        for num in nums:
            if num == mole_num:
                cnt += 1
        # print(cnt, mole_num)
        if cnt*2 <= len(nums):
            return -1
        else:
            return mole_num

s = Solution()
ya = [1,2,5,9,5,9,5,5,5]
ya = [3,2]
ya = [2,2,1,1,1,2,2]
print(s.majorityElement(ya))