class Solution:
    def findEvenNumbers(self, digits: 'List[int]') -> 'List[int]':
        d2t = {}
        for d in digits:
            d2t[d] = d2t.get(d, 0) + 1
        
        def check(n):
            n1 = n%10
            n2 = n//10 % 10
            n3 = n//100 % 10
            td2t = {}
            td2t[n1] = 1
            td2t[n2] = td2t.get(n2, 0) + 1
            td2t[n3] = td2t.get(n3, 0) + 1
            for d in td2t:
                if td2t[d] > d2t.get(d, 0):
                    return False
            return True
        
        res = []
        for n in range(100, 1000, 2):
            if check(n):
                res.append(n)
        return res