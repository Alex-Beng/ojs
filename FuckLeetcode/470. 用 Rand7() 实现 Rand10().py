# The rand7() API is already defined for you.
from random import randint
def rand7():
    return randint(1, 7)

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        ans = rand7()
        while ans > 5:
            ans = rand7()
        
        small = rand7()
        while small == 4:
            small = rand7()
        if small > 4:
            return ans
        else:
            return ans+5
