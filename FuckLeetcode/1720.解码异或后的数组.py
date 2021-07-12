class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        ans = [first]
        for ec_n in encoded:
            ans.append(ec_n^ans[-1])
        return ans