

def step1(coins, K):
    remain, answer = K, 0
    for coin in reversed(coins):
        answer += (remain//coin)
        remain %= coin

    return answer


if __name__ == '__main__':
    N, K = map(int, input().split())

    coins = []
    for _ in range(N):
        coins.append(int(input()))

    print(step1(coins, K))
