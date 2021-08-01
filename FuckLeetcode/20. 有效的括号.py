class Solution:
    def isValid(self, s: str) -> bool:
        left_c = {'(':')', '{':'}', '[':']'}
        stack = []
        for c in s:
            if c in left_c:
                stack.append(left_c[c])
            else:
                if len(stack)==0 or stack[-1]!=c:
                    return False
                del stack[-1]
        # return True if len(stack)==0 else False
        return len(stack)==0
s = Solution()
print(s.isValid(
    '()'
))