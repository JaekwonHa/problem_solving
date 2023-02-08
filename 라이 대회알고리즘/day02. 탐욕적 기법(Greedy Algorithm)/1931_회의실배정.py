import sys
input=sys.stdin.readline


def step1(rooms):
    rooms.sort(key = lambda x: x[0])
    rooms.sort(key = lambda x: x[1])

    end, answer = 0, 0
    for s, e in rooms:
        if end <= s:
            answer += 1
            end = e
    return answer
   


def step2(rooms):
    li = []
    for x in rooms:
        li.append((x[1], x[0]))
    li.sort()

    end, answer = 0, 0
    for e, s in li:
        if end <= s:
            answer += 1
            end = e
    return answer
   


if __name__ == '__main__':
    N = int(input())

    rooms = []
    for _ in range(N):
        start, end = map(int, input().split())
        rooms.append([start, end])

    print(step2(rooms))
