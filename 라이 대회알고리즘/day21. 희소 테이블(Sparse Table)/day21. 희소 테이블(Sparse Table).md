# day21. 희소 테이블(Sparse Table)
> https://m.blog.naver.com/PostView.naver?blogId=kks227&logNo=220793361738&navType=by


모든 정점의 나가는 간선이 정확히 1개인 유향 그래프가 있다고 합시다. 어떤 정점에서 시작해서 내가 정확히 k번 간선을 타고 나가겠다고 하면, k번의 이동 후 도착점이 유일하게 정해지게 되죠.

이동하는 경로가 유일할때, 이동하는 횟수를 N번이 아니라 logN번만에 찾아갈 수 있게 해주는 테크닉이다

마치 고속거듭제곱에서 A^B를 logN번의 거듭제곱으로 해결했던것 처럼..

이동을 1번, 2번, 4번, 8번, 16번 이동했을때의 도착점을 모두 만들어두는것



자료구조를 만드는 방법과 질의하는 방법을 알면 굉장히 간단하게 사용할 수 있는 테크닉이다


```java
cache[i][j] = cache[ cache[i][j-1] ][j-1]
```

여기서 `cache[i][j-1]`를 1번. 그 값을 다시 `cache[ cache[i][j-1] ][j-1]` 한다.
결국 `cache[i][j-1]`를 2번 한셈인데

i에서 2^(j+1)번 이동한 것은 i에서 2^j번을 2번 이동한 것과 같다는 뜻이다. 그래서 2번 한셈이다

그리고 j-1은 실제로는 이동횟수를 나누기2한것이다. 지수가 작아진것이기 때문에


쿼리 방법은 가장 큰 지수부터 시작한다
K번 점프해야 한다고 하면, K가 2^i 값보다 크다면 선택한다. K에서 2^i 값을 빼주고, x = `cache[x][i]` 점프


* 정해진 path를 빠르게 이동하는 문제
	- sparse table
* 정해진 path를 빠르게 이동하면서 가중치도 고려해야하는 문제
	- sparse table에 이동지점과 cost를 같이 저장



## 17435번: 합성함수와 쿼리

## 3117번: Youtube

전형적인 sparse table로 해결 가능한 문제들
이때 최대 거리의 log2 한 값만큼의 배열 크기가 필요하다는것에 주의

## 14942번: 개미

거리뿐만 아니라 가중치가 존재한다. 심지어 이 문제는 길도 없다

1. 우선 BFS로 1부터 leef 노드까지 순회를 한다. 하면서 1부터 지나온 edge를 지우거나, child -> parent 방향의 edge,cost를 다른 edges 리스트에 담아서 경로를 새로 만든다

2. 만들어진 경로와 가중치로 sparse table을 만든다

```java
    for (j in 1..MAX_M) {
        for (i in 2..n) {
            val midNode = sparseTable[i][j-1].first
            val midCost = sparseTable[i][j-1].second

            val startNode = sparseTable[midNode][j-1].first
            val startCost = sparseTable[midNode][j-1].second

            sparseTable[i][j] = startNode to (startCost + midCost)
        }
    }
```

다시 말하지만...i에서 2^(j+1)번 이동한 것은 i에서 2^j번을 2번 이동한 것과 같다
i에서 2^j 전의 지점과. 그 지점에서 다시 2^j 전의 지점. 그 각 지점 사이에 거리를 더해서 총 cost를 만든다

3. 각 노드별로 1을 향해서 sparse table로 최대 이동 가능 거리를 탐색한다

이때 이동 지점이 0(탐색이 안된 지점)이면 이동 불가
cost를 줄여가며 최대한 이동해본다





































