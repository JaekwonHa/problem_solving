import heapq
from typing import List


class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        heap = []

        visit = [False for _ in range(n)]
        count = [0 for _ in range(n)]
        for meeting in sorted(meetings):
            start, end = meeting[0], meeting[1]
            while len(heap) > 0 and heap[0][0] <= start:
                room = heapq.heappop(heap)[1]
                visit[room] = False

            if len(heap) < n:
                for i in range(n):
                    if not visit[i]:
                        heapq.heappush(heap, (end, i))
                        visit[i] = True
                        count[i] += 1
                        break
            else:
                base = 0
                while len(heap) >= n and start < heap[0][0]:
                    temp = heapq.heappop(heap)
                    base, room = temp[0], temp[1]
                    visit[room] = False
                # while len(heap) > 0 and heap[0][0] == base:
                #     room = heapq.heappop(heap)[1]
                #     visit[room] = False

                for i in range(n):
                    if not visit[i]:
                        heapq.heappush(heap, (end + (base-start), i))
                        visit[i] = True
                        count[i] += 1
                        break

        answerCount = max(count)
        for i in range(n):
            if count[i] == answerCount:
                return i

