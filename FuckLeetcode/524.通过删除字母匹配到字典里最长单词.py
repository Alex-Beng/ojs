#
# @lc app=leetcode.cn id=524 lang=python3
#
# [524] 通过删除字母匹配到字典里最长单词
#

# @lc code=start
from functools import lru_cache, cmp_to_key
class Solution:
    def findLongestWord(self, s: str, dictionary: [str]) -> str:
        @lru_cache(None)
        def cha2idx(cha):
            return ord(cha)-ord('a')
        def s2key(s):
            key = 1
            for cha in s:
                key *= 26
                key += cha2idx(cha)
            return key
        def cmp(s1, s2):
            if len(s1)!=len(s2):
                return len(s1)-len(s2)
            else:
                return s2key(s2)-s2key(s1)
        def s2vec(s):
            vec = [0]*26
            for c in s:
                vec[cha2idx(c)] += 1
            return tuple(vec)
        
        s_vec = s2vec(s)
        def valid(ts):
            tsn = len(ts)
            sn = len(s)
            sidx = 0
            tsidx = 0
            while sidx<sn and tsidx<tsn:
                if s[sidx] == ts[tsidx]:
                    tsidx += 1
                sidx += 1
            return tsidx == tsn

            # for i in range(n):
            #     if s[sidx] == ts[i]:
            #         sidx += 1
            #         continue
            #     while sidx<len(s) and s[sidx]!=ts[i]:
            #         sidx += 1
            #     if sidx == len(s):
            #         return False
            # return True
            # ts_vec = s2vec(ts)
            # print(s_vec, ts_vec)
            # for i in range(26):
            #     if ts_vec[i] > s_vec[i]:
            #         return False
            # return True

        dictionary.sort(key=cmp_to_key(cmp), reverse=True)
        print(dictionary)
        for ts in dictionary:
            print(ts)
            if valid(ts):
                print("cao?", ts)
                return ts
        return ""
s = Solution()
s.findLongestWord(
    "abpcplea",
    ["ale","apple","monkey","plea", "abpcplaaa","abpcllllll","abccclllpppeeaaaa"]
)



# @lc code=end

