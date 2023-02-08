import sys
input=sys.stdin.readline


def step1(N, K, items):
    answer = 0
    plug = {}

    for i in range(K):
        if plug.get(items[i]) is not None:
            continue

        if len(plug) < N:
            plug[items[i]] = items[i]
            continue

        candi_index = 0
        candi = None
        for p in plug:
            last_used = K
            for ii in range(i+1, K):
                if items[ii] == p:
                    last_used = ii
                    break
            if candi_index < last_used:
                candi_index == last_used
                candi = p
        
        del(plug[candi])
        plug[items[i]] = items[i]
        answer += 1

    return answer


def step2(N, K, items):
    answer = 0
    plug = set()

    for i in range(K):
        if items[i] in plug or len(plug) < N:
            plug.add(items[i])
            continue

        candi_index = -1
        candi = None
        for p in plug:
            last_used = 0
            
            for ii in range(i+1, K):
                if items[ii] == p:
                    last_used = ii
                    break
            
            if candi_index < last_used:
                candi_index = last_used
                candi = p
            
            if last_used == 0:
                candi = p
                break
        
        if candi is None:
            continue

        plug.remove(candi)
        plug.add(items[i])
        answer += 1

    return answer


def step3(N, K, items):
    answer = 0
    plug = set()

    for i in range(K):
        if items[i] in plug or len(plug) < N:
            plug.add(items[i])
            continue

        candi_index = -1
        candi = None
        for p in plug:
            last_used = 0
            
            for ii in range(i+1, K):
                if items[ii] == p:
                    last_used = ii
                    if candi_index < last_used:
                        candi_index = last_used
                        candi = p
                    break
            
            if candi_index < last_used:
                candi_index = last_used
                candi = p
            
            if last_used == 0:
                candi = p
                break

        if candi is None:
            continue

        plug.remove(candi)
        plug.add(items[i])
        answer += 1

    return answer




def step4(N, K, items):
    answer = 0
    plug = set()

    for i in range(K):
        if items[i] in plug or len(plug) < N:
            plug.add(items[i])
            continue

        candi_index = -1
        candi = None
        for p in plug:
            no_plug = True
            
            for ii in range(i+1, K):
                if items[ii] == p:
                    no_plug = False
                    if candi_index < ii:
                        candi_index = ii
                        candi = p
                    break
            if no_plug == True:
                candi = p
                break
        
        if candi is None:
            continue

        plug.remove(candi)
        plug.add(items[i])
        answer += 1

    return answer




if __name__ == '__main__':
    N, K = map(int, input().split())
    
    input = list(map(int, input().split()))

    print(step3(N, K, input))
