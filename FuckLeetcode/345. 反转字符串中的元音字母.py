class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = {'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'}

        n = len(s)
        l_ptr = 0
        r_ptr = n-1

        s = list(s)
        
        while l_ptr<r_ptr and l_ptr<n and r_ptr>=0:
            # print(l_ptr, r_ptr)
            while l_ptr<n and s[l_ptr] not in vowels:
                # print(l_ptr)
                l_ptr += 1
            while r_ptr>=0 and s[r_ptr] not in vowels:
                r_ptr -= 1
            # print(l_ptr, r_ptr)
            if l_ptr >= r_ptr:
                break
            t = s[l_ptr]
            s[l_ptr] = s[r_ptr]
            s[r_ptr] = t
            l_ptr += 1
            r_ptr -= 1
        s = ''.join(s)
        return s
s = Solution()
print(s.reverseVowels(
    # "hello"
    # "leetcode"
    # "aA"
    # "A"
    # ''
    ".,"
)
)
            