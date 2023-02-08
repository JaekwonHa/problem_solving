



def step1(query):
    penalty = 0
    current_time = 0


    for D, V in sorted(query):
        current_time += D
        penalty += (current_time + 20*V)

    return penalty


if __name__ == '__main__':
    query = []
    for _ in range(11):
        D, V = map(int, input().split())
        query.append((D,V))

    print(step1(query))

