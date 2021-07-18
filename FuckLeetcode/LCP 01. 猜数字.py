class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        ans = [1 if guess[i]==answer[i] else 0 for i in range(len(guess))]
        return sum(ans)