class Solution:
    def groupAnagrams(self, strs):
        def hash_key(s: str) -> str:
            key = [0]*26
            for c in s:
                key[ord(c)-ord('a')] += 1
            # return ''.join([str(i) for i in key])
            return tuple(key)

        same_key_strs = dict()
        for s in strs:
            key = hash_key(s)
            if key in same_key_strs:
                same_key_strs[key].append(s)
            else:
                same_key_strs[key] = [s]
        # print(list(same_key_strs.values()))
        return list(same_key_strs.values())

s = Solution()
s.groupAnagrams(["hos","boo","nay","deb","wow","bop","bob","brr","hey","rye","eve","elf","pup","bum","iva","lyx","yap","ugh","hem","rod","aha","nam","gap","yea","doc","pen","job","dis","max","oho","jed","lye","ram","pup","qua","ugh","mir","nap","deb","hog","let","gym","bye","lon","aft","eel","sol","jab"])