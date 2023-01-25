import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    N, M = map(int, readline().split())

    name_dic = {}
    index_dic = {}

    for i in range(1, N+1):
        name = readline().replace('\n', '')
        name_dic[i] = name
        index_dic[name] = i

    for _ in range(M):
        query: str = readline().replace('\n', '')
        if query.isnumeric():
            print(name_dic[int(query)])
        else:
            print(index_dic[query])
