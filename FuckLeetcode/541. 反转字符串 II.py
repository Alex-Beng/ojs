class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        n = len(s)

        for i in range(0, n, 2*k):
            if n-i<k:
                # print('cao')
                s[i:] = s[i:][::-1]
            # elif n-i>=k and n-i<2*k:
            #     print('cao', s[i:i+k])
            #     s[i:i+k] = s[i:i+k][::-1]
            else:
                s[i:i+k] = s[i:i+k][::-1]
            # print(''.join(s[i:]), n-i)
        # print(''.join(s))
        return ''.join(s)
s = Solution()
s.reverseStr(
    # 'abcdefg', 2
    'abcd', 2
)
