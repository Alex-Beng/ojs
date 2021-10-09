from functools import lru_cache
class Solution:
    def findSubstring(self, s: str, words: [str]) -> [int]:
        @lru_cache(None)
        def c2i(c):
            return ord(c)-ord('a')
        def s2vec(s):
            vec = [0]*26
            for c in s:
                vec[c2i(c)] += 1
            return vec
        
        n = len(s)
        wdn = len(words[0])
        subn = wdn*len(words)
        allwd = ''.join(words)
        allwd_vec = tuple(s2vec(allwd))

        words_dict = dict()
        for wd in words:
            if wd in words_dict:
                words_dict[wd] += 1
            else:
                words_dict[wd] = 1

        def valid(beg):
            subs = s[beg:beg+subn]
            wds = [subs[i*wdn:i*wdn+wdn] for i in range(len(words))]
            wds_dict = dict()
            for wd in wds:
                if wd in wds_dict:
                    wds_dict[wd] += 1
                else:
                    wds_dict[wd] = 1
            
            if wds_dict == words_dict:
                return True
            else:
                return False
            

        possible = []
        t_vec = None
        for i in range(0, n-subn+1):
            if i==0:
                t_vec = s2vec(s[:subn])
            else:
                t_vec[c2i(s[i-1])] -= 1
                t_vec[c2i(s[i+subn-1])] += 1

            if tuple(t_vec) == allwd_vec:
                possible.append(i)
        ans = [p for p in possible if valid(p)]
        # print( possible, ans)
        # print(set(words))
        return ans
s = Solution()
s.findSubstring(
    # "barfoothefoobarman",  ["foo","bar"]
    # "barfoofoobarthefoobarman", ["bar","foo","the"]
    # "wordgoodgoodgoodbestword", ["word","good","best","good"]
    "abaababbaba", ["ba","ab","ab"]
)
            
        