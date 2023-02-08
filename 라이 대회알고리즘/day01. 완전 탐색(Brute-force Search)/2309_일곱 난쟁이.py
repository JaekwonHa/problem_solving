import sys


def step1(hobits): 
    for a in range(0, 9):
        for b in range(a+1, 9):
            for c in range(b+1, 9):
                for d in range(c+1, 9):
                    for e in range(d+1, 9):
                        for f in range(e+1, 9):
                            for g in range(f+1, 9):
                                if hobits[a] + hobits[b] + hobits[c] + hobits[d] + hobits[e] + hobits[f] + hobits[g] == 100:
                                    return sorted([hobits[a], hobits[b], hobits[c], hobits[d], hobits[e], hobits[f], hobits[g]])
    

def step2(hobits):

    total = sum(hobits)
    
    for a in range(0, 9):
        for b in range(a+1, 9):
            if total - hobits[a] - hobits[b] == 100:
                x = hobits[a]
                y = hobits[b]
                hobits.remove(x)
                hobits.remove(y)
                hobits.sort()
                return hobits


if __name__ == '__main__':
    hobits = []
    for i in range(9):
        hobit = int(input())
        hobits.append(hobit)

    answer = step2(hobits)

    for hobit in answer:
        print(hobit)
