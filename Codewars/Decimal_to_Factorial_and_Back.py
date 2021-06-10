import math

LETTERS = [
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
]


def dec_2_fact_string(nb):
    answer = [LETTERS[0]]
    for i in range(2, 37):
        if nb <= 0:
            break
        answer.append(LETTERS[int(nb % i)])
        nb = int(nb / i)
    return ''.join(answer[::-1])


def fact_string_2_dec(string):
    answer = 0
    for idx, val in enumerate(string[::-1]):
        answer += math.factorial(idx) * int(LETTERS.index(val))
    return answer

# print(dec_2_fact_string(371993326789901217467999448150835199999999))
# print(dec_2_fact_string(463))
# print(dec_2_fact_string(2982))
# print(fact_string_2_dec("341010"))
# print(fact_string_2_dec("4042100"))
print(fact_string_2_dec("ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210"))
