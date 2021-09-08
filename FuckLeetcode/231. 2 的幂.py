class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n>0 and n&(n-1)==0 
s = Solution()
while True:
    ya = int(input())
    print(s.isPowerOfTwo(
        ya
    ))