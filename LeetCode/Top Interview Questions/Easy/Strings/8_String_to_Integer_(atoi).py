class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if len(s) == 0:
            return 0
        minus = False
        if s[0] == '-':
            minus = True
            if len(s) == 1:
                return 0
            s = s[1:]
        elif s[0] == '+':
            if len(s) == 1:
                return 0
            s = s[1:]
        lastIndex = 0
        for i in range(len(s)):
            if '0' <= s[i] <= '9':
                lastIndex = i+1
                continue
            break
        if lastIndex == 0:
            return 0
        result = int(s[0:lastIndex])
        if abs(result) > (1 << 31) - 1:
            if minus:
                return -1 * (1 << 31)
            else:
                return (1 << 31) - 1
        if minus:
            return -1 * result
        return result


solution = Solution()
print((1 << 32))
print((1 << 31))
print(solution.myAtoi("42"))
print(solution.myAtoi("    -42"))
print(solution.myAtoi("4193 with words"))
print(solution.myAtoi("words and 987"))
print(solution.myAtoi("-91283472332"))
print(solution.myAtoi("91283472332"))
