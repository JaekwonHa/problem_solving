# Top Interview Questions > Easy

# Array

## 1_Two_Sum
첫번째로 주어진 int 형 배열 속에서 서로 다른 두 수를 더해 두번째로 주어진 수가 되는 쌍의 index를 반환한다.

x + y = z 라는 수식을 z - x = y 로 거꾸로 생각할 수 있어야 하는 문제.

y를 O(1)에 조회하기 위해서 hash map을 사용해야 한다. hash map을 사용하여 해결하는게 핵심

## 26_Remove_Duplicates_from_Sorted_Array
새로운 List를 생성하는게 아니라 받은 List를 그대로 변형시켜야 한다.

같은 숫자들이 연속될때는 del로 삭제해주고 포인터를 이동시키면 된다.

## 48_Rotate_Image

테트리스 모양을 뒤집듯이 2차원 배열을 대각선으로 자른 뒤 서로 대칭점에 있는 숫자들을 교환한 뒤 2차원 배열 자체를 reverse 해준다

## 122_Best_Time_to_Buy_and_Sell_Stock_II

가격이 오름차순으로 연속될 때는 무시하고 가격이 떨어지는 순간 이전 가격(가장 비싼 가격)에서 매도하고 지금 가격에서 매수하도록 한다

## 136_Single_Number

hash table을 쓰면 O(n) / O(n) 이 풀 수 있긴하다
수학적, 컴퓨터 공학적으로도 해결이 가능한데
2 * sum(set(nums)) - sum(nums)
혹은 XOR 연산을 통해서도 해결할 수 있다

## 189_Rotate_Array

배열을 k 만큼 우측으로 밀고, 배열 크기를 벗어나는 숫자들은 왼쪽에서 차오르도록 배열을 변형시키는 문제

k 자리를 기준으로, 전체 reverse -> k 우측, 좌측을 1번씩 더 reverse 하면 해결할 수 있다

## 217_Contains_Duplicate

set 으로 hash table 로 변형한 뒤 길이를 비교하면 쉽게 해결 가능

## 66_Plus_One

list를 string, int로 변환 한 뒤에 +1 해주고 다시 list로 변환해서 풀 수도 있을 것 같다

배열의 마지막부터 loop를 돌면서 9면 다음 아이템도 보고, 9가 아니라면 +1하고 끝.

0번째까지 갔는데 9라면 첫번째 아이템으로 1을 추가해줘야 한

## 283_Move_Zeroes

0의 개수를 세면서 del로 삭제한 뒤, 마지막에 0의 개수만큼 append해준다

## 36_Valid_Sudoku

가로, 세로, 구간별로 list를 잘 자를수 있느냐의 문제
lambda식을 사용하면 쉽게 자를 수 있다

## 350_Intersection_of_Two_Arrays_II

교집합을 찾는 문제이다
단순히 중복을 찾는 문제와 다른 점은 개수도 답에 영향을 미친다는 것
hash 테이블을 만들어서 해결하는 방법도 있고, 정렬된 상태에서 이진 탐색으로 조회할 수도 있다
이진 탐색이 best 인거 같음

# Strings

## 344_Reverse_String

x, y 위치의 문자열을 XOR 연산 3번을 반복하면 추가 메모리 공간없이 치환할 수 있다

## 7_Reverse_Integer

숫자 -> 문자 변환 후 reverse 하고 다시 숫자로 변환
reverse 할때는 s[::-1] 로 간단하게 할 수 있음
python 에서 interger.MAX_VALUE 확인은 x > (1 << 31) - 1 로 확인 가능

pop, push 하는 방식으로도 풀 수 있는데
pop y/10
push y * 10 + x

## 387_First_Unique_Character_in_a_String

hash 맵 만들어서 풀이 가능

## 242_Valid_Anagram

sort 하는 것으로 쉽게 풀이 가능

## 126_Valid_Palindrome

펠린드롬이란 앞 뒤로 읽어도 똑같은 문자열
정규표현식으로 문자 제거 후에 reverse 비교로 풀이
정규표현식은 \w \W 가 반대의 의미이고 \w에는 _ 문자가 포함된다는 것에 주의

## 8_String_to_Integer_(atoi)

알고리즘 문제라기 보다는 함수 하나를 작성하는 문제
python 코드 상에서 overflow에 대한 처리가 좀 까다로웠다

## 28_Implement_strStr()

쉽게 풀면 이중 for loop 로 풀 수 있고..
제대로 풀려면 KMP, rabin karp 알고리즘으로 풀어야 한다

## 38_Count_and_Say

이전 term을 발음을 통해 현재의 term을 만드는 방식이다
재귀로 풀거나, 미리 배열을 만들어두면 더 효율적으로 해결할 수 있다

## 14_Longest_Common_Prefix

LCP 문제인데, 푸는 방법이 굉장히 다양하다
LeetCode solution 에서 소개하는 방법은 수평 스캔, 수직 스캔, 분할정복, 이진탐색, 트라이
다양한 방법으로 코딩하는 방법을 알아두면 도움이 많이 될 것 같다

# LinkedList

## 237_Delete_Node_in_a_Linked_List

Node 객체 자체가 next 변수를 통해 서로 연결되어 있기에 리스트와 삭제 대상을 따로 받지 않아도 된다
LinkedList에서 특정 노드를 삭제하는 방법은 이전 연결을 next node로 연결해주면 된다

## 19_Remove_Nth_Node_From_End_of_List

이 문제는 조금 더 생각을 필요로 한다
next 밖에 없기 때문에 뒤에 n 번째에 있는 node를 삭제하기 위해서는 트릭이 필요하다
1개의 포인터만 사용한다고 보면 우선 전체를 순회해서 length를 계산한 뒤, length - n 위치의 node를 삭제하면 된다
이때 원소가 1개인 경우에 삭제하면 빈 linkedList가 되어야 하는데, 이러면 이전노드와 다음노드를 연결하는 방식으로 삭제할 수가 없기에 제일 앞쪽에 dummy node를 추가하는 방법을 사용할 수 있다
2개의 포인터를 사용한다면 서로 n 만큼 위치 차이를 둔 뒤, 앞서가는 포인터가 끝에 다다를때 뒤쪽 포인터를 삭제하면 된다

## Reverse_Linked_List

### 반복문
O(n), O(1) 풀이법

순서를 스위치해야되니깐, 임시변수를 하나 정도는 써야겠구나..하는 생각을 해야한다. 각 단계마다 이전 node 값으로 연결해줘야하니깐 prev 변수도 하나 필요하겠구나. 라고 생각이 들면 클리어

### 재귀
O(n), O(n) 풀이법
재귀방식이라 stack space가 추가로 필요하다

재귀방식의 핵심은 n1, n2 ... nk, nk+1, nk+2 ... nm 이라고 생각해봤을때 nk 에서 로직이 수행된다고 했을때 nk+1 부터 nm 까지는 이미 리버스되었다고 생각해야한다

nk+1 ~ nm 까지는 리버스되었다 + 탈출조건 + 리턴해야하는 최종 변수가 무엇인지를 잘 생각해보면 풀이할 수 있다

## Merge_Two_Sorted_Lists

기존 리스트에 채우거나, 새로운 리스트에 작은 것부터 채우는 방법으로 생각해볼 수 있다

다만 curr 포인터에 직접 대입하는 것은 start 부터 연결되는게 끊어지는 결과를 만드므로 curr.next 에 대입하는 방식으로 연결해야한다

## Palindrome_Linked_List

팰린드롬은 짝수, 홀수 길이 모두에서 가능하다

slow, fast 2개 포인터를 두고, fast 포인터만 2칸씩 이동시키면 fast 포인터가 마지막 노드에 도착할때 slow는 절반을 이동하게 된다

이때 slow 포인터부터 reverse 한 리스트와 head 부터를 비교해보면 팰린드롬인지를 확인할 수 있다

## Linked_List_Cycle

일단 사이클 탐지는 HashMap을 사용하면 가능하다. 공간복잡도 O(N)

공간복잡도 O(1)으로 풀려면 플로이드의 find cycle 알고리즘을 사용해야한다. 이거를 사용하면 사이클이 시작하는 지점도 찾을 수 있다.

링크드리스트 문제에서 핵심은 추가적인 포인터를 사용할 줄 알아야하고 (prev, curr), 두가지 포인터를 각각 다른 step으로 전진시키면서도 생각해봐야하고, reverse해서 비교하는 것도 생각해봐야한다.


## 424_Longest_Repeating_Character_Replacement

sliding window 문제인데, tail, head를 써야할 뿐만 아니라 tail ~ head 사이에 가장 많이 등장하는 알파벳의 개수도 저장해두어야 한다.
컨셉은 "전체 길이에서 가장 개수가 많은 알파벳의 개수만큼은 생각하지 않아도 된다. 그 만큼은 k 로 바꾸지 않아도 된다."

## 844_Backspace_String_Compare

stack_s == stack_k 처럼 리스트가 동일한 item을 가졌는지 비교하는 것 보다,
''.join(stack_s) == ''.join(stack_t) 처럼 string 형태로 만들어서 비교하는게 훨씬 빠르다.


# 알고리즘 지식

## 다양한 컨셉

* set 으로 중복을 제거하는게 유리한가?
* pointer 를 두개 두는게 유리한가?
	- head, tail ?
	- slow, fast ?
* 처리하지 않아도 되는 (min, maximum 조건) 조건에서는 바로 return 해버리는게 성능이 많이 도움이 된다.
* 뒤에서부터 처리 가능한가?

## 플로이드의 순환 탐색 알고리즘(Floyd's cycle detection algorithm)

* 142. Linked List Cycle II

fast와 slow 포인터가 점 p에서 만날 때 그들이 달린 길이는 'a+2b+c'와 'a+b'이고 fast가 2배 빠르게 이동하기 때문에 a+2b+c == 2(a+b)가 됩니다. 최종적으로 우리는 'a==c'를 얻을 수 있습니다.

## 트리 순회 방법(tree traversal)

* 98. Validate Binary Search Tree
	- Inorder 예시

Inorder, Preorder, Postorder
중위순회, 전위순회, 후위순회
왼쪽>루트>오른쪽 / 루트>왼쪽>오른쪽 / 왼쪽>오른쪽>루트

stack이나 recursive로 구현한다.
stack은 DFS

Levelorder traversal
root 부터 한 레벨씩 아래로 내려간다.
level order는 Queue로 구현한다.
queue는 BFS





## Anagram

sort 해보면 두 문장이 anagrame인지 알 수 있다. sort 하는데 O(nlogn)
각 알파벳의 출현빈도를 카운팅. O(n), O(256) or (1) 상수 공간복잡도
unique 문자로만 구성이 되어 있다면 set을 사용할 수 있다. 아니라면 hashmap 으로 카운팅
출현빈도 카운팅을 bitwise 하게 한다면 공간복잡도 O(1)