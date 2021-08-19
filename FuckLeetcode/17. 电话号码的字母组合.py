class Solution:
    def letterCombinations(self, digits: str) -> [str]:
        digit2chas = {
            '2':'abc',
            '3':'def',
            '4':'ghi',
            '5':'jkl',
            '6':'mno',
            '7':'pqrs',
            '8':'tuv',
            '9':'wxyz'
        }
        n = len(digits)
        ans = []
        
        def dfs(layer, curr):
            if layer==n:
                if len(curr):
                    ans.append(''.join(curr))
                return 
            
            for cha in digit2chas[digits[layer]]:
                curr.append(cha)
                dfs(layer+1, curr)
                del curr[-1]
        
        dfs(0, [])
        # print(ans)
        return ans
s = Solution()
s.letterCombinations(
    # "23"
    "7527"
)
        
