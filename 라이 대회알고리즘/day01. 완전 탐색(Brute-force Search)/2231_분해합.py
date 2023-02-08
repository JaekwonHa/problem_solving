



def get_sum_of_digit(number):
    remain = number
    answer = 0
    while(remain > 0):
        answer += int(remain%10)
        remain /= 10
    return answer


def get_sum_of_digit_2(number):
    return list(map(int, str(number)))


def get_count_of_digit(number):
    remain = number
    answer = 0
    while(remain > 0):
        answer += 1
        remain /= 10
    return answer


def get_count_of_digit_2(number):
    return len(str(number))


def step1(number): 
    for i in range(1, 1000000):
        x = i + get_sum_of_digit(i)
        if x == number:
            return i
    return 0


def step2(number): 
    for i in range(1, number):
        x = i + get_sum_of_digit(i)
        if x == number:
            return i
    return 0


def step3(number): 
    start = number - (9*get_count_of_digit(number))
    for i in range(start, number):
        x = i + get_sum_of_digit(i)
        if x == number:
            return i
    return 0



def step4(number): 
    start = number - (9*get_count_of_digit_2(number))
    for i in range(start, number):
        x = i + get_sum_of_digit(i)
        if x == number:
            return i
    return 0



def step5(number): 
    start = number - (9*get_count_of_digit_2(number))
    for i in range(start, number):
        x = i + sum(get_sum_of_digit_2(i))
        if x == number:
            return i
    return 0


if __name__ == '__main__':
    number = int(input())

    answer = step5(number)

    print(answer)
