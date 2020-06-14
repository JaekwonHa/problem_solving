# Top Interview Questions > Easy > Array

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
