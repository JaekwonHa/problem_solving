class Solution:

    # def findLongestRepeatingCharacter(self, s: str, k: int) -> int:
    #     answer, remain = 0, k

    #     tail, head = 0, 1
    #     while head < len(s):
    #         if s[tail] != s[head] and remain > 0:
    #             remain -= 1
    #         elif s[tail] != s[head] and remain == 0:
    #             answer = max(answer, head - tail)
    #             tail += 1
    #             head = tail
    #         head += 1

    #     answer = max(answer, head - tail)
    #     return answer

    # def characterReplacement(self, s: str, k: int) -> int:
    #     if len(s) < 2:
    #         return len(s)

    #     return max(self.findLongestRepeatingCharacter(s, k), self.findLongestRepeatingCharacter(s[::-1], k))


    def characterReplacement(self, s: str, k: int) -> int:
        if len(s) < 2:
            return len(s)

        cache = {}
        answer, tail, maxCount = 0, 0, 0
        for head, c in enumerate(s):
            cache[c] = cache.get(c, 0) + 1
            maxCount = max(maxCount, cache[c])

            if head-tail+1 - maxCount > k:
                cache[s[tail]] -= 1
                tail += 1
            answer = max(answer, head-tail+1)

        return answer
