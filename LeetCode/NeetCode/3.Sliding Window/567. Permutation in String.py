from collections import defaultdict

class Solution:
    # def checkInclusion(self, s1: str, s2: str) -> bool:
    #     cash_s1 = defaultdict(int)
    #     for i in range(len(s1)):
    #         cash_s1[s1[i]] += 1
    #
    #     left, cash_s2 = 0, defaultdict(int)
    #     for right in range(len(s2)):
    #         cash_s2[s2[right]] += 1
    #
    #         if right - left + 1 == len(s1):
    #             if cash_s1 == cash_s2:
    #                 return True
    #             cash_s2[s2[left]] -= 1
    #             if cash_s2[s2[left]] == 0:
    #                 del(cash_s2[s2[left]])
    #             left += 1
    #
    #     return False

    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        window_s1 = [0 for i in range(ord('z') - ord('a') + 1)]
        window_s2 = [0 for i in range(ord('z') - ord('a') + 1)]
        counter = 0

        for i in range(len(s1)):
            window_s1[ord(s1[i]) - ord('a')] += 1
            window_s2[ord(s2[i]) - ord('a')] += 1

        for i in range(26):
            if window_s1[i] == window_s2[i]:
                counter += 1

        j = 0
        for i in range(len(s1), len(s2)):
            if counter == 26:
                break

            left, right = ord(s2[j]) - ord('a'), ord(s2[i]) - ord('a')

            if window_s1[left] == window_s2[left] - 1:
                counter += 1
            elif window_s1[left] == window_s2[left]:
                counter -= 1
            window_s2[left] -= 1
            j += 1

            if window_s1[right] == window_s2[right] + 1:
                counter += 1
            elif window_s1[right] == window_s2[right]:
                counter -= 1
            window_s2[right] += 1

        return counter == 26





s = Solution()

s1 = "ab"
s2 = "eidbaooo"
print(s.checkInclusion(s1, s2))
