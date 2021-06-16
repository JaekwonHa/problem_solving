import math


def find_squares(num):
    start = int(math.sqrt(num))
    end = int(math.pow(num, 2))
    for i in range(start, end+1):
        if i*i - (i-1)*(i-1) == num:
            return f'{i*i}-{(i-1)*(i-1)}'

    return "no-answer"


print(find_squares(1))
print(find_squares(9))
print(find_squares(5))
print(find_squares(7))
