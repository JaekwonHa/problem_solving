import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    sentence = readline().replace('\n', '')
    N = int(readline())

    prefix_sum = [[0 for _ in range(len(sentence)+1)] for _ in range(26)]

    for i in range(len(sentence)):
        for j in range(26):
            count = 1 if ord(sentence[i]) - ord('a') == j else 0
            prefix_sum[j][i+1] = prefix_sum[j][i] + count

    for _ in range(N):
        a, l, r = readline().split()
        l, r = int(l), int(r)
        print(prefix_sum[ord(a) - ord('a')][r+1] - prefix_sum[ord(a) - ord('a')][l])
