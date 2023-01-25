





def get_strike(q, c):
    q1, q2, q3 = int(q/100), int(q/10%10), int(q%10)
    c1, c2, c3 = int(c/100), int(c/10%10), int(c%10)

    answer = 0
    if q1 == c1:
        answer += 1
    if q2 == c2:
        answer += 1
    if q3 == c3:
        answer += 1
    return answer


def get_ball(q, c):
    q1, q2, q3 = int(q/100), int(q/10%10), int(q%10)
    c1, c2, c3 = int(c/100), int(c/10%10), int(c%10)

    answer = 0
    if q1 in [c2, c3]:
        answer += 1
    if q2 in [c1, c3]:
        answer += 1
    if q3 in [c1, c2]:
        answer += 1
    return answer


def step1(query):
    candi = [True for _ in range(1000)]
    for x in range(0, 10):
        for y in range(0, 10):
            for z in range(0, 10):
                if 0 in [x,y,z] or x == y or x == z or y == z:
                    candi[x*100 + y*10 + z*1] = False

    for q, s, b in query:
        for i, c in enumerate(candi):
            if c is True:
                if s != get_strike(q, i) or b != get_ball(q, i):
                    candi[i] = False

    return len(list(filter(lambda x: x, candi)))


if __name__ == '__main__':
    N = int(input())

    query = []
    for _ in range(N):
        (q, strike, ball) = map(int, input().split(' '))
        query.append((q, strike, ball))

    answer = step1(query)

    print(answer)
