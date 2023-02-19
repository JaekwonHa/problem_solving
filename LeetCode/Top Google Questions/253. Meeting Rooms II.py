from typing import List
import heapq


class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        sortedIntervals = sorted(intervals, key=lambda x: (x[0], x[1]))

        rooms = [sortedIntervals[0][1]]
        heapq.heapify(rooms)

        for i in range(1, len(intervals)):
            if sortedIntervals[i][0] >= rooms[0]:
                heapq.heappop(rooms)
            heapq.heappush(rooms, sortedIntervals[i][1])

        return len(rooms)

s = Solution()
input = [[5,8],[6,8]]
print(s.minMeetingRooms(input))

input = [[1,5],[8,9],[8,9]]
print(s.minMeetingRooms(input))

input = [[6,15],[13,20],[6,17]]
print(s.minMeetingRooms(input))

input = [[9,16],[6,16],[1,9],[3,15]]
print(s.minMeetingRooms(input))

input = [[2,15],[36,45],[9,29],[16,23],[4,9]]
print(s.minMeetingRooms(input))
