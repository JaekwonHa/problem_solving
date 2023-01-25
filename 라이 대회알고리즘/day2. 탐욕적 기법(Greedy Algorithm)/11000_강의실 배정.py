import sys

def step1(rooms):
    answer = [0]

    rooms.sort()

    for s, t in rooms:
        is_find = False
        for i in range(len(answer)):
            if answer[i] <= s:
                answer[i] = t
                is_find = True
                break
        if is_find is False:
            answer.append(t)

    return len(answer)


import heapq

def step2(rooms):
    answer = []

    rooms.sort()

    for s, t in rooms:
        if len(answer) != 0 and answer[0] <= s:
            heapq.heappop(answer)
        heapq.heappush(answer, t)
    
    return len(answer)


def step3(rooms):
    answer = [-1]

    for s, t in rooms:
        if answer[0] <= s:
            heapq.heapreplace(answer, t)
        else:
            heapq.heappush(answer, t)
    
    return len(answer)



if __name__ == '__main__':
    input=sys.stdin.readline

    N = int(input())

    rooms = sorted(tuple(map(int, input().split())) for _ in range(N))

    print(step3(rooms))
