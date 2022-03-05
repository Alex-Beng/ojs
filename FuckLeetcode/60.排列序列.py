class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        n_fact = [1]*233
        for i in range(1, 23):
            n_fact[i] = n_fact[i-1]*i

        # 构建所需的双向循环链表
        left = [-1]*233
        right = [-1]*233
        num = [-1]*233

        left[0] = 0
        right[0] = 0

        for i in range(1, n+1):
            right[i] =  right[left[0]]
            left[i] = left[0]
            right[left[i]] = i
            left[right[i]] = i
            num[i] = i

        ans = []
        def dfs(n: int, k: int):
            if n==1:
                ans.append(num[right[0]])
                return

            # 这里还可以改成二分
            ti = -1
            for i in range(1, n+1):
                # 选择第 i 个数
                if (i-1)*n_fact[n-1] < k and i*n_fact[n-1] >= k:
                    ti = i
            
            # 从双向循环链表中删去
            t_ptr = 0
            for i in range(ti):
                t_ptr = right[t_ptr]
            right[left[t_ptr]] = right[t_ptr]
            left[right[t_ptr]] = left[t_ptr]
            t_num = num[t_ptr]

            ans.append(t_num)
            dfs(n-1, k-(i*n_fact[n-1]))
        dfs(n, k)
        return ''.join([str(i) for i in ans])

if __name__ == '__main__':
    s = Solution()
    s.getPermutation(9, 100)
