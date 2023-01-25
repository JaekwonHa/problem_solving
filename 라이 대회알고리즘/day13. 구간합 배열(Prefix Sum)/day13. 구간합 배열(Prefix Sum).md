# day13. 구간합 배열(Prefix Sum)
> https://m.blog.naver.com/PostView.naver?blogId=kks227&logNo=220787178657&navType=by

어떤 N개의 원소로 이루어진 배열이 주어졌을 때 부분 배열의 합을 구하려면 반복문을 돌려서 해결할 시 O(N)이 걸리는데, 전처리를 통해 모든 부분합을 O(1)에 바로바로 구할 수 있습니다.

N개 값으로 이루어진 배열 A가 있을 때, 이것의 prefix sum은 N칸 혹은 N+1칸으로 이루어진 배열인데, 저는 후자가 훨씬 편에서 선호합니다.
이 경우 pSum[x] = 앞에서부터 x개 원소의 합을 의미하며, pSum[0] = 0입니다.
앞에서부터 배열을 쫙 보면서 pSum[i+1] = pSum[i] + A[i] 식으로 채워 나갈 수 있습니다.

2차원 prefix sum
Σ(r1 ≤ i ≤ r2, c1 ≤ j ≤ c2) A[i][j]
= pSum[r2+1][c2+1] - pSum[r1][c2+1] - pSum[r2+1][c1] + pSum[r1][c1]

당연히, 만드는 데에는 N행 M열에 대해 O(NM)의 시간이면 충분합니다.


prefix_sum은 어떠한 문제 유형이라기 보다는 트릭, 자료구조이다

몇번의 쿼리를 보내야하고, 각 쿼리에서 매번 답을 구해야할때 prefix_sum을 만들어둔다면 O(1)에 해결할 수 있다
혹은 매번 prefix_sum을 만들어야 할 수도 있다.



* prefix_sum 을 다수 쓰는 문제
	- 2,3개 혹은 알파벳 개수만큼 사용
* 2d prefix_sum
* 좌표 압축
	- prefix_sum을 배열로 할 수 없는 문제. (배열의 크기가 너무 크다) 리스트를 사용
* 매번 prefix_sum을 생성
* prefix XOR 배열




## 17203번: ΔEasyMAX|

차에 대한 배열을 만들어서 그것을 prefix_sum 으로 만듬


## 11969번: Breed Counting

ID 3가지에 대한 prefix_sum 을 각각 생성



## 16139번: 인간-컴퓨터 상호작용

알파벳 26자에 대한 모든 prefix_sum 을 계산해둔다

pypy3로 제출시에 성공


## 10211번: Maximum Subarray

모든 i,j 구간에 대해서 prefix_sum 최대값을 찾으면 O(N^2) 해결 가능



## 10986번: 나머지 합

생각해보면 어떤 구간의 합이 M으로 나누어 떨어진다는말은...prefix_sum(r) 과 prefix_sum(l)이 모두 M 으로 나누었을때 나머지가 같다는 말이다!

나머지가 같은 것들끼리의 차여야 그 결과가 M으로 나누어 떨어진다. 이 속성을 깨달아야한다


그렇다면 M의 최대값이 1000이니깐 prefix_sum에 대한 2~999 나머지에 대한 위치를 미리 계산해둔다

그럼 나머지 0에 대한 prefix_sum의 인덱스, 나머지 1에 대한 prefix_sum의 인덱스 .... 나머지 999에 대한 prefix_sum의 인덱스가 쭉 나올텐데

나머지가 같은 인덱스 중에서 2개를 고르는 조합 수의 합이 답이 된다

이때 나머지 0에 대한 인덱스로 0(zero) 인덱스를 추가해두어야 한다


## 11660번: 구간 합 구하기 5

2d prefix_sum 을 구하는 문제

```python
    N, M = map(int, readline().split())

    board = [list(map(int, readline().split())) for _ in range(N)]

    prefix_sum = [[0 for _ in range(N+1)] for _ in range(N+1)]

    # 생성
    for x in range(1, N+1):
        for y in range(1, N+1):
            prefix_sum[x][y] = board[x-1][y-1] + prefix_sum[x-1][y] + prefix_sum[x][y-1] - prefix_sum[x-1][y-1]

    # 쿼리
    for _ in range(M):
        x1, y1, x2, y2 = map(int, readline().split())

        result = prefix_sum[x2][y2] - prefix_sum[x1-1][y2] - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1]
        print(result)
```

## 11997번: Load Balancing (Silver)

2d 부분합을 구해두었다면 특정 x,y 좌표에 대해서 각 사분면의 소 개수합을 O(1)에 해결할 수 있다

근데 2d 부분합을 배열로 구하기에는... 소가 있는 x,y 좌표 자체가 1,000,000 이다. 배열로 유지할 수 없다

근데 소 자체가 최대 1000마리만 주어진다. 대부분의 좌표에는 소가 없다
x,y 좌표를 정렬해서 순서, idx를 부옇나다 (좌표 압축)

1000* 1000 으로 부분합을 구하고, 특정 x,y 좌표 O(N^2) 에 대해서 계산을 해볼 수 있다



## 16713번: Generic Queries

XOR의 특이한 연산 특징

A ^ B ^ A = B

prefix XOR 배열로 해결 가능


















































