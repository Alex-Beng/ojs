class Solution:
    def generateParenthesis(self, n: int) -> [str]:

        curr = []
        ans = set()
        def dfs(left_to_go, right_to_go):
            nonlocal curr
            # print(curr)
            if not (left_to_go|right_to_go):
                # print(''.join(curr))
                ans.add(''.join(curr))

            for i in range(1,left_to_go+1):
                curr += ['(']*i
                dfs(left_to_go-i, right_to_go+i)
                del curr[-i:]
            for i in range(1,right_to_go+1):
                curr += [')']*i
                dfs(left_to_go, right_to_go-i)
                del curr[-i:]
            
        dfs(n, 0)
        return list(ans)
s = Solution()
s.generateParenthesis(
    8
)
