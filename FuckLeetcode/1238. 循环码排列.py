from typing import List

class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        def gray_code(n: int):
            ans = ['0', '1']
            for i in range(n-1):
                ans = ['0'+i for i in ans] + ['1'+i for i in ans[::-1]]
            return [int(i, 2) for i in ans]
        gcode = gray_code(n)
        i = gcode.index(start)
        return gcode[i:] + gcode[:i]