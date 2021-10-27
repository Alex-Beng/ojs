#
# @lc app=leetcode.cn id=869 lang=python3
#
# [869] 重新排序得到 2 的幂
#

# @lc code=start
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        def num2vec(num: int) -> (int):
            vec = [0]*10
            while num != 0:
                t = num%10
                vec[t] += 1
                num //= 10
            return tuple(vec)
        two_pow_vecs = set()

        t = 1
        for i in range(30):
            two_pow_vecs.add(num2vec(t))
            t *= 2
        print(two_pow_vecs)
        return num2vec(n) in two_pow_vecs
# @lc code=end