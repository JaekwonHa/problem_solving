from unittest.test.test_suite import Test


def solution(string, markers):
    splited_array = string.split('\n')
    striped_array = []

    for word in splited_array:
        striped_word = word
        for marker in markers:
            striped_word = word.split(marker)[0].lstrip()
        striped_array.append(striped_word)
    return '\n'.join(striped_array)


print(solution("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"]))
