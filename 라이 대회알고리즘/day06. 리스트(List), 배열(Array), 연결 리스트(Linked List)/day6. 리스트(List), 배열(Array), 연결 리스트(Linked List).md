# day6. 리스트(List), 배열(Array), 연결 리스트(Linked List)






①삽입(insertion), ②삭제(deletion), ③탐색(search) 이 3가지 연산을 빨리 하기 위해 각 상황에 맞는 다양한 효율적인 자료구조들이 많이 개발되어 왔습니다.

리스트(List), 배열(Array), 연결 리스트(Linked List)

원형 연결 리스트(circular linked list),
이중 연결 리스트(doubly linked list),

연결 리스트 관련 문제는 후에 스택, 큐, 덱 등으로도 가능한 경우가 많습니다


doubly linked list, circular linked list 의 경우
파이썬에서는 deque로 쉽게 구현할 수 있다

혹은 linked list 의 경우 left stack, right stac으로 stack 두개로도 구현할 수 있다



## 1021번: 회전하는 큐

원형 연결 리스트를 deque를 사용해서 풀면 된다

* step1
	- deque를 이용한 구현


## 1158번: 조세퍼스 문제

원형 연결 리스트를 deque를 사용해서 풀면 된다

* step1
	- deque
* step2
	- 일일이 하나하나 이동시키지말고
	- (이전에 제거시킨 위치 + K - 1 )% 현재 length 를 통해서 pop 해야하는 index를 O(1)에 찾는다
		+ 이전 위치에서 K 만큼 전진 시킨 뒤, 혹시 length를 넘어갔을수도 있으니 모듈러 해준다
	- ary.pop(index) 로 한번에 해당 element를 제거한다


## 2840번: 행운의 바퀴

deque로 풀면 간단히 해결된다

다만 다른 문자로 업데이트 되면 안된다거나, 같은 문자가 두개 나오면 안된다는 조건을 잘 구현해야한다

같은 문자가 두개 나오는 경우는 문제에서 애매하게 언급되어 있어 햇갈렸다

* step1
	- deque
* step2
	- 위치를 계산해서 해결
	- 특히 이 문제는 풍선 터뜨리기와 다르게 바퀴의 수가 유지되기 때문에 위치를 간단하게 계산할 수 있다
	- idx = (idx + spin) % N


## 3190번: 뱀

리스트 챕터라는점을 빼고 보면 과연 연결리스트, deque 구현 방법이 떠올랐을지 잘 모르겠다.

구현 문제인데 조건을 잘 신경쓰면 그리 어렵진 않다

* step1
	- deque








