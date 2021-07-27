class Solution:
    def minOperations(self, target, arr) -> int:
        tn = len(target)
        an = len(arr)
        # print(tn, an)
        t_n2idx = dict()
        for i in range(tn):
            t_n2idx[target[i]] = i
        
        trans_arr = []
        for n in arr:
            if n in t_n2idx:
                trans_arr.append(t_n2idx[n])
        if len(trans_arr) == 0:
            return tn
        # trans_arr = [t_n2idx[i] if i in t_n2idx else -1 for i in arr ]
        # print(trans_arr)
        # 寻找trans_arr 中最长递增子序列
        dp = [trans_arr[0]]*len(trans_arr)
        ans = 1
        for i in range(1, len(trans_arr)):
            num = trans_arr[i]
            # print(num, dp[:ans])
            if num > dp[ans-1]:
                dp[ans] = trans_arr[i]
                ans += 1
            else:
                l = 0
                r = ans
                while l<r:
                    m = l + (r-l)//2
                    if dp[m] < num:
                        l = m+1
                    else:
                        r = m
                dp[l] = num
        # print(ans)
        return tn-ans
        


s = Solution()
print(s.minOperations([5,1,3], [9,4,2,3,4]))
print(s.minOperations([16,7,20,11,15,13,10,14,6,8],
[11,14,15,7,5,5,6,10,11,6]
))
# 11, 15, 10, 6
# 3   4   6   8
print(s.minOperations([17,18,14,13,6,9,1,3,2,20],
[18,15,14,6,6,13,15,20,2,6]))
# [1, -1, 2, 4, 4, 3, -1, 9, 8, 4]

        
        
            