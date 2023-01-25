import sys

sys.setrecursionlimit(10 ** 6)

readline = sys.stdin.readline


def get_score(contents, used_alphabet):
    answer = 0
    for content in contents:
        temp = 0
        for i in range(len(content)):
            temp += (10 ** (len(content) - i - 1)) * used_alphabet[ord(content[i])]
        answer += temp
    return answer


def get_temp_score(contents, used_alphabet):
    answer = 0
    for content in contents:
        temp = 0
        for i in range(len(content)):
            number = used_alphabet[ord(content[i])]
            if number == -1:
                number = 9
            temp += (10 ** (len(content) - i - 1)) * number
        answer += temp
    return answer


def step1(contents, alphabets, used_alphabet, used_number, idx):
    global answer
    if len(alphabets) == idx:
        answer = max(answer, get_score(contents, used_alphabet))
        return

    temp = get_temp_score(contents, used_alphabet)
    if temp <= answer:
        return

    current = alphabets[idx]
    for i in range(9, -1, -1):
        if not used_number[i]:
            used_alphabet[ord(current)] = i
            used_number[i] = True
            step1(contents, alphabets, used_alphabet, used_number, idx+1)
            used_alphabet[ord(current)] = -1
            used_number[i] = False


if __name__ == '__main__':
    N = int(readline())

    contents = [readline().replace('\n', '') for _ in range(N)]

    # alphabets = set()
    # for i in range(N):
    #     for j in range(len(contents[i])):
    #         alphabets.add(contents[i][j])
    #
    # used_alphabet = [-1 for _ in range(ord('Z') + 1)]
    # used_number = [False for _ in range(10)]
    #
    # alphabets = list(alphabets)
    # alphabets.sort()
    # answer = 0
    # step1(contents, alphabets, used_alphabet, used_number, 0)
    # print(answer)


    alphabets_list = {}
    for content in contents:
        for i in range(len(content)):
            alphabets_list.setdefault(content[i], 0)
            alphabets_list[content[i]] += (10**(len(content)-i-1))

    alphabets_list = list(alphabets_list.items())
    alphabets_list = sorted(alphabets_list, key=lambda x: (x[1]), reverse=True)

    number = 9
    answer = 0
    for alphabet, score in alphabets_list:
        answer += score * number
        number -= 1

    print(answer)
