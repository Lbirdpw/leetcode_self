#include <stdio.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) 
{
    int iRes = 0;
    for (int row = 0; row < gridRowSize; ++row)        
    {
        for (int col = 0; col < gridColSize; ++col)
        {
            if (0 == grid[row][col])
            {
                continue;
            }
            if (0 == row)
            {
                iRes += 1;
            }
            if (0 == col)
            {
                iRes += 1;
            }
            if (gridRowSize - 1 == row)
            {
                iRes += 1;
            }
            if (gridColSize - 1 == col)
            {
                iRes += 1;
            }
            
            
            if (row > 0 && 0 == grid[row - 1][col])
            {
                iRes += 1;
            }
            if (col > 0 && 0 == grid[row][col - 1])
            {
                iRes += 1;
            }
            if (row + 1 < gridRowSize && 0 == grid[row + 1][col])
            {
                iRes += 1;
            }
            if (col + 1 < gridColSize && 0 == grid[row][col + 1])
            {
                iRes += 1;
            }
            
        }
    }
    return iRes;
}
