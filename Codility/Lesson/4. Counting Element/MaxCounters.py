def solution(N, A):
    # write your code in Python 3.6
    max_counter = 0
    max_value = 0
    counter = {}
    for a in A:
        if N < a:
            counter = {}
            max_counter += max_value
            max_value = 0
            continue
        counter.setdefault(a, 0)
        counter[a] += 1
        max_value = max(max_value, counter[a])

    f = lambda i: max_counter if counter.get(i) is None else max_counter + counter[i]
    return list(map(f, range(N+1)))[1:]