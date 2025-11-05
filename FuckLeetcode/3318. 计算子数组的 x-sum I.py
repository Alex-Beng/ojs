class Solution:
    def findXSum(self, nums: 'List[int]', k: int, x: int) -> 'List[int]':
        N = len(nums)
        res = []
        for beg in range(N-k+1):
            # print(nums[beg:beg+k])
            n2t = {}
            for n in nums[beg:beg+k]:
                n2t[n] = n2t.get(n, 0) + 1
            ns = list(n2t.keys())
            ns.sort(key=lambda _n: (n2t[_n], _n), reverse=True)
            res.append(sum( _n * n2t[_n] for _n in ns[:x] ))
        return res
INPUT = [
    ([1,1,2,2,3,4,2,3], 6, 2),
    ([3,8,7,8,7,5], 2, 2),
]