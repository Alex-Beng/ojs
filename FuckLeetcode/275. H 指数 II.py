from time import sleep
class Solution:
    def hIndex(self, citations) -> int:

        n = len(citations)
        def is_h_pnt(i):
            if citations[i] >= n-i:
                return True
            else:
                return False
        
        l = 0
        r = n
        while l < r:
            # 错误示范，可能溢出，虽然py随意
            # m = int((l+r)/2) 
            m = l+ (r-l)//2

            if is_h_pnt(m):
                r = m
            else:
                l = m+1
        return n-l

            
s = Solution()
print(s.hIndex( [10] ))