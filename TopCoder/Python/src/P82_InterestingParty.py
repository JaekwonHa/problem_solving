import sys

def main():

    with open("res/P82_InterestingParty.txt", "r") as f:
        sys.stdin = f

        N = input()
        m = {}
        for s in input().split(' '):
            m.setdefault(s, 0)
            m[s]+=1
        for s in input().split(' '):
            m.setdefault(s, 0)
            m[s]+=1

        answer = max(m, key=m.get)

        print(m[answer])

if __name__=="__main__":
    main()