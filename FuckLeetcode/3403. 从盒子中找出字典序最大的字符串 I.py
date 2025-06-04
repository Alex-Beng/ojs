class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        N = len(word)
        if numFriends == 1: return word

        res = None
        for i in range(N):
            
            j = min(N - numFriends + i, N-1)
            # print(i, j)
            subWord = word[i:j+1]
            # print(subWord)
            if res is None or subWord > res:
                res = subWord
        return res
INPUT = [
    # ("dbca", 2)
    ("dah", 3)
]