from functools import lru_cache
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        cha2word = dict()
        word2cha = dict()
        words = s.split(' ')
        if len(words) != len(pattern):
            return False
        
        for i,cha in enumerate(pattern):
            word = words[i]
            if cha in cha2word and word in word2cha:
                # check eq
                if cha2word[cha] != word or word2cha[word] != cha:
                    return False
            elif cha not in cha2word and word not in word2cha:
                # add map
                cha2word[cha] = word
                word2cha[word] = cha
            else:
                return False
        return True
s = Solution()
print(s.wordPattern(
    "abba", "dog dog dog dog"
))