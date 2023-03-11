from typing import List
from functools import reduce

class Solution:

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            if self.isInvalid(board[i]):
                return False

        for i in range(9):
            if self.isInvalid(list(map(lambda x: x[i], board))):
                return False

        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                if self.isInvalid(reduce(lambda x, y: x + y, (map(lambda x: x[j:j+3], board[i:i+3])))):
                    return False

        return True

    def isInvalid(self, row: List[str]) -> bool:
        nums = list(filter(lambda x: x != ".", row))
        return len(nums) != len(set(nums))


solution = Solution()
solution.isValidSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]])


