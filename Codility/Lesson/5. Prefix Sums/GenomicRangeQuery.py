def solution(S, P, Q):
    # write your code in Python 3.6
    letters = {}
    letters['A'] = 1
    letters['C'] = 2
    letters['G'] = 3
    letters['T'] = 4
    K = len(P)
    answer = []
    for i in range(K):
        start = P[i]
        end = Q[i]
        temp = letters[S[start]]
        for i in range(start+1, end+1):
            temp = min(temp, letters[S[i]])
        answer.append(temp)
    return answer