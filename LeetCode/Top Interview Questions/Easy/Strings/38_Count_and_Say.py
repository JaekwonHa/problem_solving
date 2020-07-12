class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"

        exResult = self.countAndSay(n - 1)

        result = ""
        last_char = exResult[0]
        series_count = 0
        for i in range(len(exResult)):
            if last_char == exResult[i]:
                series_count += 1
                continue
            result += str(series_count) + last_char
            last_char = exResult[i]
            series_count = 1
        result += str(series_count) + last_char

        return result


solution = Solution()
print(solution.countAndSay(1))
print(solution.countAndSay(2))
print(solution.countAndSay(3))
print(solution.countAndSay(4))
print(solution.countAndSay(5))


