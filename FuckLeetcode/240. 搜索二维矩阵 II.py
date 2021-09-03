class Solution:
    def searchMatrix(self, matrix: [[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        def bin_search(arr):
            L = 0
            R = n-1
            while L<=R:
                m = (L+R)//2
                if arr[m]<target:
                    L = m+1
                elif arr[m]>target:
                    R = m-1
                else:
                    return True
            return False
        for row in matrix:
            if row[0]<=target and target<=row[-1] and bin_search(row):
                return True
        return False
    def searchMatrix(self, matrix: [[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        row, col = m-1, 0
        while row>=0 and col<n:
            if matrix[row][col] < target:
                col += 1
            elif matrix[row][col] > target:
                row -= 1
            else:
                return True
        return False
s = Solution()
print(s.searchMatrix(
    # [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 5
    # [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 20
    # [[1,1]], 0
    [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 5
))
            