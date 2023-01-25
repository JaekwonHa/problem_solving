# day18. 세그먼트 트리(Segment Tree)
> https://m.blog.naver.com/PostView.naver?blogId=kks227&logNo=220791986409&navType=by
> https://www.geeksforgeeks.org/segment-tree-efficient-implementation/

* Tree Construction: O( n )
* Query in Range: O( Log n )
* Updating an element: O( Log n )

구간의 정보를 가지고 있는 자료구조

구간합, 구간최소값, 구간최대값 등을 logN에 계산할 수 있다

구현하는 방법은 다양하다

kotlin에서 비재귀적인 방법으로 아래와 같이 구현했다

```java
private fun build(numbers: LongArray) {

    // insert leaf nodes in tree
    for (i in 0 until treeSize) {
        tree[treeSize+i] = numbers[i]
    }

    // build the tree by calculating
    // parents
    for (i in treeSize-1 downTo 0) {
        tree[i] = tree[i shl 1] + tree[(i shl 1) or 1]
    }
}

private fun updateTreeNode(pos: Int, value: Long) {
    // set value at position pos
    var p = pos
    tree[treeSize + p] = value
    p += treeSize

    while (p > 1) {
        tree[p shr 1] = tree[p] + tree[p xor 1]
        p = p shr 1
    }
}

private fun query(left: Int, right: Int): Long {
    var res = 0L

    // loop to find the sum in the range
    var (l, r) = (left + treeSize to right + treeSize)
    while (l < r) {
        if ((l and 1) > 0) {
            res += tree[l]
            l += 1
        }
        if ((r and 1) > 0) {
            r -= 1
            res += tree[r]
        }

        l = l shr 1
        r = r shr 1
    }

    return res
}
```

1,2,3,4,5 처럼 5개의 원소가 있을때, 아래와 같이 배치가 된다

                      		  15(1)
                   10(2) 				      5(3)
             9(4)   	  1(5) 		     2(6) 		3(7)
          4(8)    5(9)

5개라는 숫자가 2의 제곱이 아니기 때문에
treeSize = 5 이기 때문에
5,6,7,8,9 번째에 배치가 된다

원소의 개수 - 1개의 부모노드를 가진다

업데이트 방법은
먼저 treeSize + p 를 통해서 리프노드를 바로 업데이트한다
그리고 그 상위 부모노드들을 모두 업데이트 해준다.
> 부모를 찾아가는 방법 p >> 1. 나누기 2씩 해준다. 나누기 2를 했을때 홀수일수도 있고, 짝수일수도 있다. 그래서 반대쪽 노드는 xor 를 취해준다

깊이가 logN 이라서 logN 만에 업데이트 가능하다

쿼리 방법은
left, right 를 역시 리프노드로 한번에 옮겨준다

왼쪽 리프노드가 홀수라면, 그 노드만 더해줘야 한다. 그래서 해당 리프노드의 값을 더해주고 +1 해준다. 그러면 이미 홀수(오른쪽파트)인데 +1이 되었기에 왼쪽 subtree에서 필요한 것을 모두 취하게 된다
오른쪽 리프노드가 홀수라면, 그 노드빼고 왼쪽파트만 더해주면 된다. 그래서 해당 리프노드의 값에서 -1 하고, 더해준다. 그러면 오른쪽 리프노드 subtree 에서 필요한 값을 모두 취할 수 있다

shr
값이 작아진다. 점점 루트 쪽으로 이동
shl
값이 커진다. 점점 리프노드 쪽으로 이동


* 구간합
* 구간곱
* 구간최소값, 구간최대값
* 값 업데이트가 아닌 값 추가
* LIS(Longest Increasing Sequence)
    - 2d DP
    - lower_bound
    - segment tree
* 구간합(업데이트가 있는)
    - 구간합 prefix_sum은 구간합을 구하는데 O(1)이 가능하지만, 업데이트는 O(N)이다.
    - 구간합 segment_tree는 구간합을 구하는데 O(logN), 업데이트 O(logN)
* 구간합, 구간개수. 세그먼트 트리 2개 사용하는 문제
* 구간최소값 + 구간최대값. 2개 세그먼트 트리 사용
* greedy + 세그먼트 트리
    - 어쨋든 세그먼트 트리를 쓰려면..문제를 구간합 혹은 구간개수 혹은 둘다 쓰는 문제로 일반화를 시켜야 한다
    - 혹은 index -> 결과값(좌표) 의 문제를 결과값(좌표) -> index,item 이런식으로 바꿔서 생각할 줄 알아야한다
        + 바이너리 서치의 left, right 전체 범위 생각하듯이
* 앞쪽으로 빼내는(- 좌표계를 사용하는) 업데이트가 발생하는 세그먼트 트리
* 변형 segement tree
    - binary search + segment tree
* greedy + 세그먼트 트리
    - 2336번: 굉장한 학생
        + 1번째 조건은 정렬로 회피
        + 2번째 조건은 segment tree의 index로 회피
        + 3번째 조건은 segment tree의 value로 회피



## 2042번: 구간 합 구하기

segment 트리를 쓰는 경우 값이 매우 커질 수 있기 때문에 데이터 타입에 주의
여기서는 단순 합이라서 Long 타입으로 해결 가능

## 11505번: 구간 곱 구하기

동일한 문제. Long 타입에 모듈러 연산을 해야한다.
이때 아래와 같이 하면 출력오류 발생. 연산시 Long 타입을 넘어갈 수 있다
> 결과에 모듈러 연산이 수행되지 않는다!!

```java
res *= tree[l] % 1000000007
```

아래와 같이 해야한다

```java
res = (res * tree[l]) % 1000000007
```

## 12837번: 가계부 (Hard)

구간 합 구하기.

근데 값을 업데이트하는게 아니라 값을 추가해주는 것이다.



## 12015번: 가장 긴 증가하는 부분 수열 2

LIS 구하는 문제인데 kotlin 은 DP+바이너리 서치로 해결했다.
세그먼트트리로는 해결 안됨


## 1275번: 커피숍2

x, y 중 x가 더 큰 경우도 있을 수 있다
query 시에 x, y를 포함하는지 안포함하는지 신경써야한다

## 2268번: 수들의 합

x, y 중 x가 더 큰 경우도 있을 수 있다
query 시에 x, y를 포함하는지 안포함하는지 신경써야한다

## 3745번: 오름세

LIS 자체는 lower_bound로 해결이 가능

kotlin 에서 EOF를 받는 방법과 입력에 공백이 여러개 주어질 수 있다는 점을 주의


## 1365번: 꼬인 전깃줄

최장 증가 수열을 구하는 문제

lower bound: 324ms
segment tree: 492ms

처음에는 최장 감소 수열이 답이 되는 경우도 있지 않을까?
라고 생각했는데...이건 오른쪽 전봇대의 index 배열을 보는 것이니깐 감소 수열은 의미가 없다.
수가 감소하면 다 꼬인다는 뜻

## 3006번: 터보소트

구간합 prefix_sum은 구간합을 구하는데 O(1)이 가능하지만, 업데이트는 O(N)이다.
구간합 segment_tree는 구간합을 구하는데 O(logN), 업데이트 O(logN)

숫자를 하나씩 옮길수록 그 자리의 숫자가 빠져서, 이후 swap을 할때 해당 자리는 건너뛰어도 되는 것이다.
따라서 구간에 몇개의 수가 남았는지를 logN에 조회할 수 있다면 해결 가능

이때 segment tree 범위를 주의해야하는데..
left는 포함이지만, right는 포함되지 않는다

## 1280번: 나무 심기

나무를 순서대로 심기때문에, 세그먼트트리를 순서대로 업데이트해준다면,
현재 쿼리를 진행할때 1번~i번 나무까지 밖에 없게된다.
따라서 세그먼트트리에 있는 모든 나무를 대상으로 cost를 계산해나가면 된다

왼쪽 나무들의 cost 계산법과 오른쪽 나무들의 cost 계산법이 다르다

```java
        val leftCost: Long = ((a*leftCount) - leftSum) % mod
        val rightCost: Long = (rightSum - (a*rightCount)) % mod

        answer = (answer * ((rightCost + leftCost) % mod)) % mod
```

이때 세그먼트트리의 pos 는 좌표가 되어야한다. 넘버링이 아니라
따라서 넘버링을 0-based 표기법으로 바꿀 필요가 없다. 그냥 좌표 그 자체를 쿼리하고 업데이트해주면 된다
(이것때문에 많이 틀렸다)

뭔가 이런 문제 스타일은 codeforce 스타일인것같다.
greedy하게 cost를 계산할 수 있는 방법이 있고, 그 방법을 빠르게 구현하려면 세그먼트트리를 써야하는 식

## 3653번: 영화 수집

영화를 앞에 세울때, 영화의 위치~1번자리까지의 모든 영화의 수를 -1 업데이트 해줘야할까?
전체 영화의 위치를 N개가 아니라 -M ~ +N 까지의 위치가 있다고 해보자
영화를 볼때마다 -M 영역에 쌓는다 + 영화의 원래 위치를 0으로 업데이트해준다. (세그먼트트리 업데이트 2번)
각 영화의 위치는 map으로 O(1)에 조회한다


구간합 0 ~ 영화의 위치를 구해서 앞에 몇개가 있는지 조회한다

## 9345번: 디지털 비디오 디스크(DVDs)

각 자리에는 반드시 1개의 비디오가 있다.
특정 구간에서의 비디오 개수는 반드시 구간의 개수와 일치한다
따라서 구간에서의 최소값과 최대값을 알고있고, 최소값과 최대값 사이의 숫자 개수가 구간과 일치하면다면 답이라고 볼 수 있다

구간최소값 + 구간최대값. 2개 세그먼트 트리 사용


## 2243번: 사탕상자

전체에서 k번째로 작은 수를 찾아야 합니다. 그리고 중복되는 값이 여러 개일 수도 있네요.

* step1
    - binary search + segment tree
    - 1 ~ 1,000,000 범위로 이진 탐색
    - 파라메트릭 서치처럼 사탕의 맛 범위를 이진 탐색. 각 구간에서의 사탕 개수를 segment tree로 조회
* step2
    - 변형 segement tree
    - 왼쪽 구간, 오른쪽 구간을 나눠서 쿼리를 이어갈때 왼쪽 구간의 사탕 개수가 지금 찾으려는 rank보다 크다면, 그만큼 빼고 오른쪽에서 탐색한다
    - bottom-up 방식이 아니라 top-down. DFS 방식으로 가능하다
    
```java
fun query(left: Int, right: Int, node: Int, rank: Int): Int {
    if (left == right) {
        return node - s + 1
    }
    val mid = (left + right) / 2
    return if (candy[node * 2] >= rank) {
        query(left, mid, node * 2, rank)
    } else {
        query(mid + 1, right, node * 2 + 1, rank - candy[node * 2])
    }
}
```

## 2336번: 굉장한 학생

시험이 총 3번있다. 3번의 비교를 해야한다.

시험 점수가 좋은 학생부터 본다면..이미 지나왔던 학생 중에서 2,3번째 시험 점수만 봐도 되지 않을까?
지금 트리에 반영된 학생들을 '나보다 첫번째 시험 점수가 좋았던 학생들'로 생각해본다면

2번째 시험 점수는 어떻게 비교할 수 있을까
나보다 2번째 시험 등수가 낮은 구간을 보면 되지 않을까

나보다 2번째 시험 등수가 낮은 구간에서 나보다 3번째 시험 등수가 낮은 사람이 나온다면
이 사람은 나보다 1번째, 2번째, 3번째 시험 등수가 모두 낮은 사람이다.

이러한 사람이 있다면 나는 굉장한 학생이 되지 못한다.
아니라면 나는 굉장한 학생이다.

1번째 조건은 정렬로 회피
2번째 조건은 segment tree의 index로 회피
3번째 조건은 segment tree의 value로 회피










































