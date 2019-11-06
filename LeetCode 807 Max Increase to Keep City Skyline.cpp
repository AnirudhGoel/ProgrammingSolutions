class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        result = 0
        
        topBottom = [0] * len(grid[0])
        leftRight = list()
        for row in grid:
            leftRight.append(max(row))
            for x in range(len(row)):
                if row[x] > topBottom[x]:
                    topBottom[x] = row[x]
                    
        for x in range(len(grid)):
            for y in range(len(grid[x])):
                if grid[x][y] != min(leftRight[x], topBottom[y]):
                    result += abs(grid[x][y] - min(leftRight[x], topBottom[y]))
                    
        return result
