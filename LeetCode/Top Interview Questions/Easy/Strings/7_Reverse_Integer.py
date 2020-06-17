class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        if x < 0:
            s = str(-x)
            result = - int(s[::-1])
        else:
            s = str(x)
            result = int(s[::-1])
        if abs(result) > (1 << 31) - 1:
            return 0
        return result
