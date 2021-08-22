class Solution:
    def findDifferentBinaryString(self, nums: [str]) -> str:
        n = len(nums)

        been = set(nums)
        for i in range(0, 2**n):
            t_n = bin(i)[2:]
            zeros = ['0']*(n-len(t_n))
            t_n = ''.join(zeros) + t_n
            # print(t_n)
            if t_n not in been:
                return t_n
        
s = Solution()
print(s.findDifferentBinaryString(
    #  ["00","01"]
    ["111","011","001"]
))