import re

class Solution:
    def mostCommonWord(self, paragraph: str, banned: 'List[str]') -> str:
        paragraph = re.sub(r'[],.?! ]+', ' ', paragraph).strip()
        # print(paragraph)
        words = [wd.strip("!?',;.").lower() for wd in paragraph.split(' ')]
        # print(words)
        wd2times = dict()
        for wd in words:
            if wd in wd2times:
                wd2times[wd] += 1
            else:
                wd2times[wd] = 1
        for wd in banned:
            if wd in wd2times:
                del wd2times[wd]
        return max(wd2times, key=lambda k: wd2times[k])
INPUT = [
    ("Bob hit a ball, the hit BALL flew far after it was hit.", ["hit"]),
    ("a, a, a, a, b,b,b,c, c", ["a"])
]