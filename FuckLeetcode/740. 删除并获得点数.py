class Solution:
    def deleteAndEarn(self, nums) -> int:
        n2time = dict()
        for n in nums:
            if n in n2time:
                n2time[n] += 1
            else:
                n2time[n] = 1

        keys = list(n2time.keys())
        keys.sort()

        kn = len(keys)
        curr_value = [n2time[key]*key for key in keys]
        dp = [0]*kn

        def is_neigh(n1, n2): # n2>n1
            if n2-n1 == 1:
                return True
            else:
                return False

        if kn == 1:
            return curr_value[0]
        elif kn == 2:
            if is_neigh(keys[0], keys[1]):
                return max(curr_value)
            else:
                return sum(curr_value)

        dp[0] = curr_value[0]
        dp[1] = max(curr_value[0], curr_value[1]) if is_neigh(keys[0], keys[1]) else sum(curr_value[:2])
        for i in range(2, kn):
            if keys[i]-1 in n2time: # 邻居也是key
                dp[i] = max(dp[i-1], dp[i-2]+curr_value[i])
            else:
                dp[i] = dp[i-1] + curr_value[i]
        # print(dp)
        return dp[kn-1]
                

s = Solution()
print(s.deleteAndEarn([3,4,2]))