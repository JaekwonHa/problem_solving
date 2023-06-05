from typing import List

class Solution:
    # def findMinDifference(self, timePoints: List[str]) -> int:
    #     candidates = []
    #     for s in timePoints:
    #         h, m = map(int, s.split(':'))
    #         t_1 = h * 60 + m
    #         t_2 = t_1 + 1440
    #         candidates.append(t_1)
    #         candidates.append(t_2)
    #
    #     candidates.sort()
    #
    #     answer = 1e9
    #     for i in range(1, len(candidates)):
    #         answer = min(answer, abs(candidates[i] - candidates[i-1]))
    #
    #     return answer


    def findMinDifference(self, timePoints: List[str]) -> int:
        candidates = []
        for s in timePoints:
            h, m = map(int, s.split(':'))
            t_1 = h * 60 + m
            candidates.append(t_1)

        candidates.sort()

        answer = 1440 - (candidates[-1] - candidates[0])
        if answer < 0:
            answer += 1440
        for i in range(1, len(candidates)):
            answer = min(answer, abs(candidates[i] - candidates[i-1]))
            if answer == 0:
                break

        return answer


s = Solution()
timePoints = ["23:59","00:00"]
print(s.findMinDifference(timePoints))

timePoints = ["00:00","23:59","00:00"]
print(s.findMinDifference(timePoints))
