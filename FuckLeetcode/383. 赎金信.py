class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        cnts = [0]*26

        for cha in magazine:
            cnts[ord(cha)-ord('a')] += 1
        
        for cha in ransomNote:
            cnts[ord(cha)-ord('a')] -= 1
        
        for c in cnts:
            if c<0:
                return False
        return True