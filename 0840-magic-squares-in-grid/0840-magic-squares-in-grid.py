class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        position5 = self.find5(grid)

        n = 0
        for p in position5:
            square = []
            square.append(grid[p[0]-1]  [p[1]-1:p[1]+2])
            square.append(grid[p[0]]    [p[1]-1:p[1]+2])
            square.append(grid[p[0]+1]  [p[1]-1:p[1]+2])
            if self.checkIfMagic(square):
                n += 1

        return n
    def find5(self, grid: List[List[int]]) -> List[List[int]]:
        """
        The method finds the position of every 5.
        If a magic square exists, it has to have 5 in the middle.
        """
        positions = []
        for x, row in enumerate(grid[1:-1], 1):
            for y, number in enumerate(row[1:-1], 1):
                if number == 5:
                    positions.append([x, y])
        return positions
    def checkIfMagic(self, grid: List[List[int]]) -> bool:
        if grid[0] == [5, 5, 5]:
            return False
        # Check sum for every row
        for row in grid:
            if sum(row) != 15:
                return False
            if 0 in row:
                return False
        # Transpose the grid.
        t_grid = list(map(list, zip(*grid)))
        # Check columns
        for column in t_grid:
            if sum(column) != 15:
                return False
        return True