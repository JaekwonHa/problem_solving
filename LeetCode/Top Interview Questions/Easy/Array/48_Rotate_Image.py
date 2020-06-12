from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        depth = len(matrix) - 1
        for i in range(depth):
            for j in range(depth - i):
                diff = depth - i - j
                matrix[i][j], matrix[i + diff][j + diff] = matrix[i + diff][j + diff], matrix[i][j]

        matrix.reverse()


matrix = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

solution = Solution()
solution.rotate(matrix)
print(matrix)

