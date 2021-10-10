class Solution:
    def dailyTemperatures(self, temperatures: [int]) -> [int]:

        n = len(temperatures)
        ans = [0]*n
        sk = []
        for i,temp in enumerate(temperatures):
            while len(sk) and temp > temperatures[sk[-1]]:
                j = sk.pop()
                ans[j] = i-j
            sk.append(i)
        return ans
s = Solution()
r = s.dailyTemperatures(
    # [73,74,75,71,69,72,76,73]
    [30,40,50,60]
)
print(r)