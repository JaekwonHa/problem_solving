class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t):
            return ""

        cash_s = [0 for _ in range(ord('z') - ord('A') + 1)]
        cash_t = [0 for _ in range(ord('z') - ord('A') + 1)]

        for i in range(len(t)):
            cash_t[ord(t[i]) - ord('A')] += 1

        min_length = 987654321
        answer = ""
        left, right = 0, 0

        while right < len(s):
            cash_s[ord(s[right]) - ord('A')] += 1

            while left <= right and self.match(cash_s, cash_t):
                if (right - left + 1) < min_length:
                    min_length = (right - left + 1)
                    answer = s[left:right+1]
                cash_s[ord(s[left]) - ord('A')] -= 1
                left += 1

            right += 1

        return answer

    def match(self, cash_s: [], cash_t: []) -> bool:
        for i in range(len(cash_s)):
            if cash_t[i] > cash_s[i]:
                return False
        return True


solution = Solution()

s = "ADOBECODEBANC"
t = "ABC"
print(solution.minWindow(s, t))

s = "ab"
t = "a"
print(solution.minWindow(s, t))

s = "aa"
t = "aa"
print(solution.minWindow(s, t))
