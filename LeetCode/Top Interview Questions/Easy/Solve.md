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
push y*10 + x

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

