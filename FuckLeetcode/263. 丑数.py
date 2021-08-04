class Solution:
    def __init__(self):
        self.fector = [2,3,5]
    def isUgly(self, n: int) -> bool:
        if n==1:
            return True
        elif n==0:
            return False
        for f in self.fector:
            if n%f == 0:
                print(f)
                return self.isUgly(n//f)
        return False

s = Solution()
print(s.isUgly(6))