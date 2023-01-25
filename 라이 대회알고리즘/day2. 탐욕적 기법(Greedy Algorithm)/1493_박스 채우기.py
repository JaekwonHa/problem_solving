import sys
input=sys.stdin.readline


def step1(L, W, H, N, input):
    remain = L * W * H
    answer = 0

    for a, b in input[::-1]:
        volume = pow(pow(2, a), 3)
        count = min(remain // volume, b)
        answer += count
        remain -= count * volume

    return answer if remain == 0 else -1




block = []
find = True

def step2_recursive(L, W, H):
    if L == 0 or W == 0 or H == 0:
        return 0

    block_length = 0
    partial_index = -1
    for i in range(len(block)):
        block_length = 1 << block[i][0]
        if block_length <= L and block_length <= W and block_length <= H and block[i][1] > 0:
            partial_index = i
            block[partial_index] = (block[partial_index][0], block[partial_index][1]-1)
            return (1 
            + step2_recursive(L, block_length, H - block_length)
            + step2_recursive(L, W - block_length, H)
            + step2_recursive(L - block_length, block_length, block_length))

    global find
    find = False
    return 0


def step2(L, W, H, N):
    block.sort(reverse = True)
    # answer = step2_recursive(1<<L, 1<<W, 1<<H)
    answer = step2_recursive(L, W, H)
    return answer if find is True else -1
   

def step3_recursive(L, W, H):
    if L == 0 or W == 0 or H == 0:
        return 0
    if (L == 1 or W == 1 or H == 1) and block[-1][0] == 0:
        if L == 1 and W == 1 and H != 1:
            if H <= block[-1][1]:
                block[-1] = (block[-1][0], block[-1][1]-H)
                return H
        if L == 1 and W != 1 and H == 1:
            if W <= block[-1][1]:
                block[-1] = (block[-1][0], block[-1][1]-W)
                return W
        if L != 1 and W == 1 and H == 1:
            if L <= block[-1][1]:
                block[-1] = (block[-1][0], block[-1][1]-L)
                return L

    block_length = 0
    partial_index = -1
    for i in range(len(block)):
        block_length = 1 << block[i][0]
        if block_length <= L and block_length <= W and block_length <= H and block[i][1] > 0:
            # count = min(L//block_length, W//block_length, H//block_length, block[i][1])
            count = 1
            block_length *= count
            
            partial_index = i
            block[partial_index] = (block[partial_index][0], block[partial_index][1]-count)
            # if block[partial_index][1] == 0:
            #     del(block[partial_index])
            
            return (count
            + step3_recursive(L, block_length, H - block_length)
            + step3_recursive(L, W - block_length, H)
            + step3_recursive(L - block_length, block_length, block_length))

    global find
    find = False
    return 0


def step3(L, W, H, N):
    block.sort(reverse = True)
    # answer = step2_recursive(1<<L, 1<<W, 1<<H)
    answer = step3_recursive(L, W, H)
    return answer if find is True else -1


def step4(L, W, H, N):
    block.sort(reverse = True)

    volume = 0
    count = 0

    for a, b in block:
        current_size = 1 << a
        current_count = (L//current_size)*(W//current_size)*(H//current_size)

        volume *= 8
        count += min(b, current_count - volume)
        volume += min(b, current_count - volume)

    if volume == L*W*H:
        return count
    else:
        return -1


if __name__ == '__main__':
    L, W, H = map(int, input().split())

    N = int(input())

    block = [tuple(map(int, input().split())) for _ in range(N)]

    print(step4(L, W, H, N))
