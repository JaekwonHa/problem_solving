from typing import List

class Solution:
    def latestTimeCatchTheBus(self, buses: List[int], passengers: List[int], capacity: int) -> int:
        buses.sort()
        passengers.sort()

        last_bus_capacity = 0
        last_pass_time = 0
        j = 0
        for i in range(len(buses)):
            last_bus_capacity = 0
            while j < len(passengers) and passengers[j] <= buses[i] and last_bus_capacity < capacity:
                last_bus_capacity += 1
                last_pass_time = passengers[j]
                j += 1

        answer = 1
        if last_bus_capacity < capacity:
            answer = buses[-1]
        else:
            answer = last_pass_time

        hash = set(passengers)
        while answer in hash:
            answer -= 1

        return answer



s = Solution()
buses = [10,20]
passengers = [2,17,18,19]
capacity = 2
print(s.latestTimeCatchTheBus(buses, passengers, capacity))

buses = [20,30,10]
passengers = [19,13,26,4,25,11,21]
capacity = 2
print(s.latestTimeCatchTheBus(buses, passengers, capacity))

buses = [3]
passengers = [2]
capacity = 2
print(s.latestTimeCatchTheBus(buses, passengers, capacity))

buses = [5]
passengers = [3, 4, 5, 6]
capacity = 3
print(s.latestTimeCatchTheBus(buses, passengers, capacity))

buses = [2]
passengers = [2]
capacity = 2
print(s.latestTimeCatchTheBus(buses, passengers, capacity))

buses = [2, 10, 30]
passengers = [2]
capacity = 2
print(s.latestTimeCatchTheBus(buses, passengers, capacity))
