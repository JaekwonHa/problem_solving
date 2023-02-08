import sys
readline=sys.stdin.readline


def step1(N, H, input):
    lb, rb = 1, int(1e18)

    while lb <= rb:
        hero_health = (lb + rb)//2
        hero_attack = H

        for i in range(N):
            if input[i][0] == 1:
                monster_health = input[i][2]
                monster_attack = input[i][1]
                count = monster_health//hero_attack-1
                monster_health -= count*hero_attack
                hero_health -= count*monster_attack
                while 0 < monster_health and 0 < hero_health:
                    monster_health -= hero_attack
                    if 0 < monster_health:
                        hero_health -= monster_attack
                if hero_health <= 0:
                    break
            else:
                hero_health = min(hero_health+input[i][2], (lb + rb)//2)
                hero_attack += input[i][1]

        if 0 < hero_health:
            rb = (lb + rb)//2 - 1
        else:
            lb = (lb + rb)//2 + 1
    return lb


if __name__ == '__main__':
    N, H = map(int, readline().split())

    input = [list(map(int, readline().split())) for _ in range(N)]

    print(step1(N, H, input))
