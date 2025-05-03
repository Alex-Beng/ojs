class Solution:
    def numEquivDominoPairs(self, dominoes: 'List[List[int]]') -> int:
        
        pair2num = {}
        for d in dominoes:
            dHash = (min(d), max(d))
            pair2num[dHash] = pair2num.get(dHash, 0) + 1
        res = 0
        for k, v in pair2num.items():
            if v > 1:
                res += v*(v-1) // 2
        return res
        