class Solution:
    def circularArrayLoop(self, nums) -> bool:
        n = len(nums)

        def dfs(layer, curr_idx, is_pos, been):
            # print(curr_idx, nums[curr_idx], been)

            
            next_idx = (curr_idx + nums[curr_idx])%n
            next_num = nums[next_idx]
            # print(f'{curr_idx} to {next_idx}')

            if next_idx == curr_idx:
                return False
            if been[next_idx] and layer > 1:
                # print('cao', curr_idx, nums[curr_idx], been)
                return True

            if (is_pos and next_num>0) or (not is_pos and next_num<0):
                been[next_idx] = 1
                return dfs(layer+1, next_idx, is_pos, been)
            else:
                return False
        
        for i in range(n):
            t_res = dfs(0, i, nums[i]>0, [0 if j!=i else 1 for j in range(n)])
            # print(i, t_res)
            if t_res:
                return True
        return False
s = Solution()
print(s.circularArrayLoop(
    # [2,-1,1,2,2]
    # [-1,2]
     [-2,1,-1,-2,-2]
    # [2,-1,1,-2,-2]
    # [2,2,2,2,2,4,7]
))
            
        