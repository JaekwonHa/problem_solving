# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         answer = 0
#         for i in range(len(s)):
#             cash = set()
#             for j in range(i, len(s)+1):
#                 if j == len(s) or s[j] in cash:
#                     answer = max(answer, j-i+1-1)
#                     break
#                 else:
#                     cash.add(s[j])
#
#         return answer
# O(N^2)


# O(N)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        answer = 0
        cash = set()
        i, j = 0, 0
        while i < len(s):
            if s[i] not in cash:
                cash.add(s[i])
                answer = max(answer, len(cash))
                i += 1
                continue

            while j < i and s[i] in cash:
                cash.remove(s[j])
                j += 1

        return answer
