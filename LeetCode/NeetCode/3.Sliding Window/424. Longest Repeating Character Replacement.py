from collections import defaultdict


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        answer, left, maxCount, cash = 0, 0, 0, defaultdict(int)

        for right in range(len(s)):
            cash[s[right]] += 1
            maxCount = max(maxCount, cash[s[right]])

            if (right-left+1) - maxCount > k:
                cash[s[left]] -= 1
                left += 1

            answer = max(answer, (right-left+1))
        return answer
