def perfect_team_of_minimal_size(n, candidates) -> int:
    if len(candidates) == 0:
        return -1

    answer = 987654321
    for i in range(len(candidates)):
        candi = set(candidates[i])
        answer = min(answer, perfect_team_of_minimal_size_recursive(n, 2, candi, candidates[i+1:]))
    return answer if answer != 987654321 else -1


def perfect_team_of_minimal_size_recursive(n, choice, candi, remain) -> int:
    if len(candi) == n:
        return choice

    if len(remain) == 0:
        return 987654321

    answer = 987654321
    for i in range(len(remain)):
        answer = min(answer, perfect_team_of_minimal_size_recursive(n, choice + 1, candi.union(set(remain[i])), remain[i+1:]))
    return answer


candidates = [[0, 2],
              [1, 2],
              [0, 1],
              [0]]


print(perfect_team_of_minimal_size(3, candidates))
