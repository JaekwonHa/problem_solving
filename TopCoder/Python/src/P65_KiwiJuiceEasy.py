import sys

def main():

    with open("res/P65_KiwiJuiceEasy.txt", "r") as f:
        sys.stdin = f

        N = int(sys.stdin.readline())
        capacities, bottles = [], []

        capacities = list(map(int, sys.stdin.readline().split()))
        bottles = list(map(int, sys.stdin.readline().split()))

        M = int(sys.stdin.readline())
        fromId, toId = [], []

        fromId = list(map(int, sys.stdin.readline().split()))
        toId = list(map(int, sys.stdin.readline().split()))

        for i in range(M):
            f, t = fromId[i], toId[i]
            sum = bottles[f] + bottles[t]

            bottles[t] = min(sum, capacities[t])
            bottles[f] = sum - bottles[t]

        for i in range(N):
            print(bottles[i], end=' ')


if __name__=="__main__":
    main()