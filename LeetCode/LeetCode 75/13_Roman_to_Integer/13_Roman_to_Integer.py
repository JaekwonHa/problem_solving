class Solution:
    def romanToInt(self, s: str) -> int:
        symbol_map = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        prev = ''
        result = 0
        for c in s:
            result += symbol_map[c]
            if (c == 'V' or c == 'X') and prev == 'I':
                result -= 2 * symbol_map[prev]
            if (c == 'L' or c == 'C') and prev == 'X':
                result -= 2 * symbol_map[prev]
            if (c == 'D' or c == 'M') and prev == 'C':
                result -= 2 * symbol_map[prev]
            prev = c
            
        return result


solution = Solution()

s = "MCMXCIV"
print(solution.romanToInt(s))