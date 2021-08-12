class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        cha = [0]*26
        for c in sentence:
            cha[ord(c)-ord('a')] = 1
        if sum(cha) == 26:
            return True
        else:
            return False