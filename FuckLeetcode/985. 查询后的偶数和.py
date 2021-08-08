class Solution:
    def sumEvenAfterQueries(self, nums, queries):
        even_sum = 0
        for n in nums:
            if n%2 == 0:
                even_sum += n
        
        ans = []
        for q in queries:
            if nums[q[1]]%2 == 0:
                even_sum -= nums[q[1]]
            
            nums[q[1]] += q[0]                
            if (nums[q[1]])%2 == 0:
                    even_sum += nums[q[1]]   
            ans.append(even_sum)
        return ans

s = Solution()
print(s.sumEvenAfterQueries(
     [1,2,3,4], 
     [[1,0],[-3,1],[-4,0],[2,3]]
    # [3,2],
    # [[4,0],[3,0]]
))