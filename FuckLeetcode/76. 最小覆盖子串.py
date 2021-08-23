from functools import lru_cache

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n = len(s)
        @lru_cache(None)
        def get_idx(cha):
            return ord(cha)-ord('A')

        t_feature_vec = [0]*60
        for cha in t:
            t_feature_vec[get_idx(cha)] += 1
        s_feature_vec = [0]*60
        for cha in s:
            s_feature_vec[get_idx(cha)] += 1
        def check(ya):
            # check valid substr vec
            for i in range(60):
                if ya[i]<t_feature_vec[i]:
                    return False
            return True
        
        if not check(s_feature_vec):
            return ""

        l_ptr = 0
        r_ptr = 0
        curr_vec = [0]*60
        ans = float('inf')
        ansl = ansr = -1
        t_set = set(t)
        
        while r_ptr<n:
            while r_ptr<n and not check(curr_vec) :
                curr_vec[get_idx(s[r_ptr])] += 1
                r_ptr += 1
            if r_ptr-l_ptr<ans:
                ans = r_ptr-l_ptr
                ansl = l_ptr
                ansr = r_ptr

            while check(curr_vec):
                curr_vec[get_idx(s[l_ptr])] -= 1
                l_ptr += 1

            if r_ptr-l_ptr<ans:
                ans = r_ptr-l_ptr+1
                ansl = l_ptr-1
                ansr = r_ptr
        return s[ansl:ansr] 
s = Solution()
print(s.minWindow(
    # "ADOBECODEBANC", "ABC"
    # "ADOBECODEBANC", "ABC"
    # "a", "a"
    # "a", "aa"
    "ab", "a"
))