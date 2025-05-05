class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        res = eval(f"({num1.replace('i', 'j')}) * ({num2.replace('i', 'j')})")
        return f"{int(res.real)}+{int(res.imag)}i"
INPUT = [
    ("1+1i", "1+1i")
]
