import re


def solve_runes(runes):

    r = re.compile('(-?[0-9?]*)([-+*])(-?[0-9?]*)=(-?[0-9?]*)')
    m = r.search(runes)

    one, op, two, three = m.group(1), m.group(2), m.group(3), m.group(4)

    p = re.compile('.*00+.*')

    result = -1
    for i in range(9,-1,-1):
        if runes.find(str(i)) > 0:
            continue
        one_ = one.replace('?', str(i))
        two_ = two.replace('?', str(i))
        three_ = three.replace('?', str(i))

        if i == 0 and p.match(one) is not None:
            continue
        if i == 0 and p.match(two) is not None:
            continue
        if i == 0 and p.match(three) is not None:
            continue
        if eval(str(''.join([one_,op,two_]))) == int(three_):
            result = i

    return result

print(solve_runes("-7715?5--484?00=-28?9?5"))
print(solve_runes("123*45?=5?088"))
print(solve_runes("-5?*-1=5?"))
print(solve_runes("19--45=5?"))
print(solve_runes("??*1=??"))

