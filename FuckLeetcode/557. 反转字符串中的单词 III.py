class Solution:
    def reverseWords(self, s: str) -> str:
        wds = s.split(' ')
        for i,wd in enumerate(wds):
            wds[i] = wd[::-1]
        return ' '.join(wds)