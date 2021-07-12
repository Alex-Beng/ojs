class Solution:
    def dfs(self, layer, curr_sum):
        if layer == self.lens:
            self.ans += curr_sum
            return

        self.dfs(layer+1, curr_sum)
        curr_sum ^= self.nums[layer]
        self.dfs(layer+1, curr_sum)
    '''
    def subsetXORSum(self, nums: list) -> int:
        self.nums = nums
        self.lens = len(nums)
        self.ans = 0
        self.dfs(0, 0)
        return self.ans
    '''

    def subsetXORSum(self, nums: list) -> int:
        candidates = [0]
        for x in nums:
            
            candidates += [x^y for y in candidates]
            print(candidates)
        return sum(candidates)

    
if __name__ == '__main__':
    solver = Solution()
    nums = [5,1,6]
    nums = [1,3]
    print(solver.subsetXORSum(nums))
    
