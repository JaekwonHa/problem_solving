import sys

sys.setrecursionlimit(10 ** 6)
readline = sys.stdin.readline

vowels = ['a', 'e', 'i', 'o', 'u']


def step1(L, alphabets, idx, answer):
    if len(answer) == L:
        vowel_count = 0
        consonant_count = 0
        for c in answer:
            if c in vowels:
                vowel_count += 1
            else:
                consonant_count += 1
        if vowel_count >= 1 and consonant_count >= 2:
            print(answer)
            return

    for i in range(idx, len(alphabets)):
        step1(L, alphabets, i+1, answer + alphabets[i])


if __name__ == '__main__':
    L, C = map(int, readline().split())

    alphabets = readline().split()
    alphabets.sort()

    for i in range(len(alphabets)):
        step1(L, alphabets, i+1, alphabets[i])
