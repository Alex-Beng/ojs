MOD = int(1e9+7)

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: 'List[int]') -> int:
        def matrix_mult(A, B):
            """矩阵乘法"""
            n = len(A)
            m = len(B[0])
            p = len(B)
            result = [[0] * m for _ in range(n)]
            
            for i in range(n):
                for j in range(m):
                    for k in range(p):
                        result[i][j] += A[i][k] * B[k][j]
                    result[i][j] %= MOD
            
            return result

        def matrix_pow(A, n):
            """矩阵快速幂"""
            size = len(A)
            result = [[1 if i == j else 0 for j in range(size)] for i in range(size)]  # 单位矩阵
            base = A
            
            while n > 0:
                if n % 2 == 1:
                    result = matrix_mult(result, base)
                base = matrix_mult(base, base)
                n //= 2
            
            return result

        def matrix_vector_mult(A, v):
            """矩阵乘以向量"""
            n = len(A)
            m = len(v)
            result = [0] * n
            
            for i in range(n):
                for j in range(m):
                    result[i] += A[i][j] * v[j]
            
            return result
        
        def vector_matrix_mult(v, A):
            """向量左乘以矩阵"""
            n = len(v)
            m = len(A[0])
            result = [0] * m
            
            for j in range(m):
                for i in range(n):
                    result[j] += v[i] * A[i][j]
            
            return result

        
        M = [[0]*26 for _ in range(26)]
        for i, n, in enumerate(nums):
            for j in range(1, n+1):
                M[i][(i+j)%26] = 1
        
        tM = matrix_pow(M, t)
        ts = [0] * 26
        for c in s:
            ts[ord(c)-ord('a')] += 1
        resT = vector_matrix_mult(ts, tM)
        return sum(resT) % MOD
        
            

INPUT = [
    # ("abcyy", 2, [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]),
    # ("u", 5, [1,1,2,2,3,1,2,2,1,2,3,1,2,2,2,2,3,3,3,2,3,2,3,2,2,3])
    # ("k", 2, [2,2,1,3,1,1,2,3,3,2,1,2,2,1,1,3,1,2,2,1,3,3,3,2,2,1])
    ("eizckbbdrrcntybngnwodjrzwsqxlyjcnkkpntnmrmzgcaookxozndnrwwarzlpprokssrdeoakcetekjykkalqzdlrne", 3783, [9,7,3,5,7,9,7,6,3,5,4,5,3,7,7,10,1,3,10,1,5,3,5,7,6,3]
)
]