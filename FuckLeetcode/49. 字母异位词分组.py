class Solution:
    def groupAnagrams(self, strs) :
        def get_key(s):
            key = [0]*26
            for w in s:
                key[ord(w)-ord('a')] += 1
            # return ' '.join([str(i) for i in  key])
            return tuple(key)
        
        key2s = dict()
        for s in strs:
            key = get_key(s)
            # print(key)
            if key in key2s:
                key2s[key].append(s) 
            else:
                key2s[key] = [s]
        return list(key2s.values())

s = Solution()
s.groupAnagrams(["bdddddddddd","bbbbbbbbbbc"])