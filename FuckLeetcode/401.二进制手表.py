#
# @lc app=leetcode.cn id=401 lang=python3
#
# [401] 二进制手表
#

# @lc code=start
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> [str]:
        ans = []
        def addTime(bits: [int]):
            hb = bits[:4]
            mb = bits[4:]

            h = 0
            m = 0

            cnt = 1
            for i in range(4):
                h += hb[i]*cnt
                cnt *= 2
            cnt = 1
            for i in range(6):
                m += mb[i]*cnt
                cnt *= 2
        
            if m>=60 or h>=12:
                return 
            else:
                ans.append(f'{h}:{m:02}')
        def dfs(layer, bitnum, bits):
            if bitnum == turnedOn:
                addTime(bits)
                return
            if layer == 10:
                return
            bits[layer] = 1
            dfs(layer+1, bitnum+1, bits)
            bits[layer] = 0
            dfs(layer+1, bitnum, bits)
            return 
        dfs(0, 0, [0]*10)
        # print(ans)
        return ans
# @lc code=end

s = Solution()
s.readBinaryWatch(1)
# for i in range(0, 11):
#     s.readBinaryWatch(i
#     )