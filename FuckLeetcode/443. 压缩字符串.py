class Solution:
    def compress(self, chars: [str]) -> int:
        n = len(chars)
        curr_idx = 0
        curr = chars[0]
        ans = 0
        cnt = 0
        while curr_idx < n:
            t = curr_idx
            curr = chars[curr_idx]
            # print(t, curr)
            bias = 0
            while curr_idx+1<n and chars[curr_idx+1]==curr:
                curr_idx += 1
                bias += 1

            if bias!=0:
                
                for nc in [curr]+list(f'{bias+1}'):
                    chars[cnt] = nc
                    cnt += 1
                
                ans += (1+len(f'{bias+1}'))
                curr_idx += 1
            else:
                chars[cnt] = curr
                cnt += 1

                ans += 1
                curr_idx += 1
        print(ans)
        return ans
s = Solution()
a = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
t = s.compress(
    #  ["a","a","b","b","c","c","c"]
    # ['a']
    a
)
print(a[:t])
                
            