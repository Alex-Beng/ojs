class Solution:
    def isCovered(self, ranges, left: int, right: int) -> bool:
        def in_array(array, n):
            if array[0]<=n and n<=array[1]:
                return 1
            else:
                return 0

        for n in range(left, right+1):
            ins = [in_array(ary, n) for ary in ranges]
            if sum(ins) == 0:
                return False
        return True
            

s = Solution()
print(s.isCovered(  [[1,10],[10,20]], 21, 21))