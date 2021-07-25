class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def get_idx(w):
            return ord(w)-ord(' ')
        n = len(s)
        if n==0 or n==1:
            return n
        l_ptr = 0
        r_ptr = 0
        curr_map = [-1]*128
        # print(get_idx(s[0]))
        curr_map[get_idx(s[0])] = 0
        ans = 1
        while r_ptr<n-1:
            # print(l_ptr, r_ptr)
            if curr_map[ get_idx(s[r_ptr+1]) ] == -1:
                curr_map[ get_idx(s[r_ptr+1]) ] = r_ptr+1
                r_ptr += 1
            else:
                n_l_ptr = curr_map[ get_idx(s[r_ptr+1]) ] + 1
                for i in range(l_ptr, n_l_ptr):
                    curr_map[ get_idx(s[i]) ] = -1

                l_ptr = n_l_ptr
                # print(l_ptr)
                curr_map[ get_idx(s[r_ptr+1]) ] = r_ptr+1
                r_ptr += 1
            # print(l_ptr, r_ptr)
            # print()
            ans = max(r_ptr-l_ptr+1, ans)
            
        return ans
s = Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))