# NeetCode
> https://neetcode.io/practice

## 2.Two Pointers

처음과 마지막의 포인터를 가지고 왼쪽, 오른쪽의 상태를 비교해서 크면 오른쪽을 움직이고, 작으면 왼쪽을 움직이고 같은 방식으로 생각해야된다.

### 167. Two Sum II - Input Array Is Sorted

정렬된 상태에서 처음과 마지막의 포인터를 가지고 특정 값을 만족시키게끔 포인터를 움직인다
target이 현재 합보다 크다면 값을 크게 만들어야하기 때문에 왼쪽 포인터를 이동시킨다
target이 현재 합보다 작다면 값을 작게 만들어야하기 때문에 오른쪽 포인터를 이동시킨다

### 15. 3Sum

하나의 값을 fix 시킨다면, Two Sum II 문제로 부분 문제를 해결할 수 있다
Two Pointer 문제가 보통 O(N)인데, 이 문제는 N^2이다 (근데 inner for-loop의 규모가 점점 작아진다)

중복되는 값들이 있기 때문에 테크닉이 좀 필요하다
여기서는 왼쪽 값을 고정시키고, 오른쪽 부분에서만 two pointer 검색을 수행했다
이렇게 하면 왼쪽 값 자체가 1번씩 검색되기 때문에 중복 값이 생기지 않는다 (+정렬되어있기 때문에)

혹은 set(sorted(())) 같은 방식..

### 42. Trapping Rain Water

답이 잘 안떠올라서 한번 손으로 풀어봤다

0 -> stack [] -> stack[(0,0)], max_height 0
1 -> stack[(0,0)], max_height 0 -> stack[(1,1)], max_height 1, answer = 0
0 -> stack[(1,1)], max_height 1 -> stack[(0,2), (1,1)], max_height 1, answer = 0
2 -> stack[(0,2), (1,1)], max_height 1 -> stack[(2,3)], max_height 2, answer = 0+1
1 -> stack[(2,3)], max_height 2, answer = 1 -> stack[(1,4), (2,3)], max_height 2, answer = 1
0 -> stack[(1,4), (2,3)], max_height 2, answer = 1 -> stack[(0,5), (1,4), (2,3)], max_height 2, answer = 1
1 -> stack[(0,5), (1,4), (2,3)], max_height 2, answer = 1 -> stack[(1,6), (0, 5), (1,4), (2,3)], max_height 2, answer = 1
3 -> stack[(1,6), (0,5), (1,4), (2,3)], max_height 2, answer = 1 -> stack[(3,7)], max_height 3, answer = 1+1+2+1+0
2 -> stack[(3,7)], max_height 3, answer = 5 -> stack[(2,8), (3,7)], max_height 3, answer = 5
1 -> stack[(2,8), (3,7)], max_height 3, answer = 5 -> stack[(1,9), (2,8), (3,7)], max_height 3, answer = 5
2 -> stack[(1,9), (2,8), (3,7)], max_height 3, answer = 5 -> stack[(2,10), (1,9), (2,8), (3,7)], max_height 3, answer = 5
1 -> stack[(2,10), (1,9), (2,8), (3,7)], max_height 3, answer = 5 -> stack[(1,11), (2,10), (1,9), (2,8), (3,7)], max_height 3, answer = 5

stack[(1,11), (2,10), (1,9), (2,8), (3,7)], max_height 0, answer = 0
이걸 reverse해서 한번더 돌린다

stack을 사용하는 방법 외에 two pointer로 높이가 낮은 쪽을 옮기면서 해결할 수 도 있다
한쪽 중 높이가 낮은 쪽은 무조건 그만큼은 물이 찬다
