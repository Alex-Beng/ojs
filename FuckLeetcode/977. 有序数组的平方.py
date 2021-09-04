class Solution:
    def sortedSquares(self, nums: [int]) -> [int]:
        '''
        执行用时：60 ms, 在所有 Python3 提交中击败了73.49%的用户
        内存消耗：16.4 MB, 在所有 Python3 提交中击败了41.10%的用户
        '''
        n = len(nums)
        pos_beg = n
        for i in range(n):
            if nums[i]>=0:
                pos_beg = i
                break
        
        neg_nums = nums[:pos_beg][::-1]
        pos_nums = nums[pos_beg:]
        
        if len(neg_nums)==0:
            return [i*i for i in nums]
        elif len(pos_nums)==0:
            return [i*i for i in nums][::-1]
        
        neg_ptr = 0
        pos_ptr = 0
        neg_n = len(neg_nums)
        pos_n = len(pos_nums)
        ans = []
        while neg_ptr<neg_n and pos_ptr<pos_n:
            t_neg = neg_nums[neg_ptr]
            t_pos = pos_nums[pos_ptr]
            if -t_neg > t_pos:
                ans.append(t_pos*t_pos)
                pos_ptr += 1
            elif -t_neg < t_pos:
                ans.append(t_neg*t_neg)
                neg_ptr += 1
            else:
                ans.append(t_neg*t_neg)
                ans.append(t_neg*t_neg)
                pos_ptr += 1
                neg_ptr += 1

        while neg_ptr<neg_n:
            t_neg = neg_nums[neg_ptr]
            ans.append(t_neg*t_neg)
            neg_ptr += 1
        while pos_ptr<pos_n:
            t_pos = pos_nums[pos_ptr]
            ans.append(t_pos*t_pos)
            pos_ptr += 1
        return ans
    def sortedSquares(self, nums: [int]) -> [int]:
        '''
        执行用时：116 ms, 在所有 Python3 提交中击败了16.56%的用户
        内存消耗：16.5 MB, 在所有 Python3 提交中击败了22.08%的用户
        '''
        n = len(nums)
        l = 0
        r = n-1
        ans = [0]*n
        ans_pos = n-1
        while l<=r:
            ln = nums[l]
            rn = nums[r]
            if ln**2 > rn**2:
                ans[ans_pos] = ln**2
                l += 1
            else:
                ans[ans_pos] = rn**2
                r -= 1
            ans_pos -= 1

        return ans

s = Solution()
print(s.sortedSquares(
    [-4,-1,0,3,10]
    # [-7,-3]
    # [-1,2,2]
))
                
        
        
        