class Solution:
    def grayCode(self, n: int) -> [int]:
        codes = ['0', '1']
        for _ in range(n-1):
            codes = ['0'+i for i in codes] + ['1'+i for i in codes][::-1]
            # print(codes)
        return [int(t, 2) for t in codes]


s = Solution()
print(s.grayCode(2))