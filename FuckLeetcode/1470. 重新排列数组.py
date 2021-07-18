class Solution:
    def shuffle(self, nums, n: int):
        first = nums[:n]
        second = nums[n:]
        return [first[i//2] if i%2==0 else second[i//2] for i in range(len(nums))]


class Solution:
	def shuffle(self,nums,n):
		nums[::2],nums[1::2]=nums[:n],nums[n:]
		return nums

        
s = Solution()
a = s.shuffle([2,5,1,3,4,7], 3)
print(a)