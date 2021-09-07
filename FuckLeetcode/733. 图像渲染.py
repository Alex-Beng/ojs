class Solution:
    def floodFill(self, image: [[int]], sr: int, sc: int, newColor: int) -> [[int]]:
        row = len(image)
        col = len(image[0])

        currColor = image[sr][sc]
        if currColor == newColor:
            return image
        image[sr][sc] = newColor
        dr = [1,-1,0,0]
        dc = [0,0,1,-1]
        for i in range(4):
            nr = sr + dr[i]
            nc = sc + dc[i]
            if nr>=0 and nr<row and nc>=0 and nc<col and image[nr][nc]==currColor:
                self.floodFill(image, nr, nc, newColor)
        return image
s = Solution()
img = [[1,1,1],[1,1,0],[1,0,1]]
img = [[0,0,0],[0,1,1]]
s.floodFill(
    # img, 1,1,2
    img,1,1,1
)
for i in img:
    print(i)
    