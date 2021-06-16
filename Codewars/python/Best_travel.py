def choose_best_sum(t, k, ls):
    if len(ls) < k:
        return None

    answer = None
    for i in range(0, len(ls)):
        result = choose_sum_recursive(t - ls[i], k - 1, ls[i+1:])
        if result is not None:
            if answer is None:
                answer = result
            else:
                answer = min(answer, result)

    return t - answer if answer is not None else None


def choose_sum_recursive(t, k, remain):
    if t < 0 or k < 0:
        return None

    if k == 0:
        return t

    answer = None
    for i in range(0, len(remain)):
        result = choose_sum_recursive(t - remain[i], k - 1, remain[i+1:])
        if result is not None:
            if answer is None:
                answer = result
            else:
                answer = min(answer, result)

    return answer


xs = [100, 76, 56, 44, 89, 73, 68, 56, 64, 123, 2333, 144, 50, 132, 123, 34, 89]
# xs = [100, 76, 56]

print(choose_best_sum(200, 3, xs))
print(choose_best_sum(230, 4, xs))
print(choose_best_sum(430, 5, xs))
print(choose_best_sum(430, 8, xs))


# test.assert_equals(choose_best_sum(230, 4, xs), 230)
# test.assert_equals(choose_best_sum(430, 5, xs), 430)
# test.assert_equals(choose_best_sum(430, 8, xs), None)
