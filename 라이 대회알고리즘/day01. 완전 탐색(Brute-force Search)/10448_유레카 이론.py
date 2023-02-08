

cache = {}
cache_2 = {}


def step1(number):
    for x in range(1, number):
        for y in range(1, number):
            for z in range(1, number):
                xx = int((x * (x+1))/2)
                yy = int((y * (y+1))/2)
                zz = int((z * (z+1))/2)
                if xx + yy + zz == number:
                    return 1
    return 0


def step2(number):
    for x in range(1, number):
        for y in range(1, number):
            xx = int((x * (x+1))/2)
            yy = int((y * (y+1))/2)
            zz = number - xx - yy
            if zz < 0:
                break
            if cache.get(zz) is not None:
                return 1
    return 0


def step3(number):
    for x in range(1, number):
        xx = int((x * (x+1))/2)
        if xx >= number:
            break
        for y in range(1, number):
            yy = int((y * (y+1))/2)
            if xx + yy >= number:
                break

            zz = number - xx - yy
            if zz < 0:
                break
            if cache.get(zz) is not None:
                return 1
    return 0


def step4(number):
    for xx in cache:
        for yy in cache:
            if xx + yy >= number:
                break
            if cache.get(number-xx-yy) is not None:
                return 1
    return 0
    

def step5(number):
    for xx in cache:
        if xx >= number:
            break
        if cache_2.get(number-xx) is not None:
            return 1
    return 0


if __name__ == '__main__':

    for x in range(1, 1000):
        triple_number = int((x * (x+1))/2)
        cache[triple_number] = x

    for xx in cache:
        for y in range(1, 45):
            yy = int((y * (y+1))/2)
            if xx + yy > 1000:
                break
            cache_2[xx+yy] = True


    n = int(input())
    for _ in range(n):
        answer = step5(int(input()))
        print(answer)
