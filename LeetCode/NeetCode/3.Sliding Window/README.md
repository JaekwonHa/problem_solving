## 3.Sliding Window

left, right 쓰는 것은 Two Pointer와 유사
window 내부의 element 들을 저장하는 dict 정도를 사용하는 트릭이 필요


### 424. Longest Repeating Character Replacement

앞에서부터 순차적으로 봐야하는데, 어떠한 window, 구간은 현재 element가 기준이 아니라 현재 element를 교체해야하는 경우도 있다.
따라서 기준을 그렇게 잡으면 안되고..

지금 element와 기존에 파악하고 있던 가장 많이 등장한 문자 개수와 비교하여 더 큰 것을 기준으로 하고 나머지를 다 교체한다고 생각해야한다
(greedy)

그래서 전체 window 길이에서 가장 많이 등장한 문자 개수를 빼면 현재 window에서 교체를 진행한 횟수를 알 수 있다

### 567. Permutation in String

근데 여기서도 s1아 s2보다 길면 답자체가 성립이 안된다. 이런 엣지케이스를 항상 먼저 거르고 시작하는게 좋을 것 같다

sort로도 해결가능하다! O(NlogN)
두개의 문장이 같은 permutation을 가지는지 확인하려면 그 구간을 잘라서 정렬해서 비교하면 된다

hashmap, array, sliding window로 해결이 가능한데 O(N)
영어 소문자로만 이뤄져있기 때문에 26개의 array를 sliding window로 사용하는 테크닉이 가능하다

hashmap, array 방법은 매번 두번째 for-loop를 시작할때 hashmap, array를 새로 쌓는다
그래서 N^2이 되고

sliding window 테크닉은 이것과는 다르다. window(dict) 내부에 element와 빈도수. 모두가 같으면 정답이 된

최적화해보면 26자 알파벳에 대한 전체 빈도수(counter)를 유지하고 특정 구간에서 그게 26이 된다면 (없는 겻들은 빈도수가 0일테니 서로 같게된다) 정답이 되는 식으로 생각해볼 수 있다


### 76. Minimum Window Substring

시간이 좀 걸리긴 했지만 Hard 문제도 솔루션없이 해결했다는게 뿌듯하다

two pointer 방식은 left, right 위치가 중요하고 left, right 비교를 통해 어느 것을 움직일지 결정하는 거였다면,
sliding window 방식은 left, right를 유지하기는 하는데 그 구간의 element를 담고 있는 window(array or dict)가 필요하다
현재 window가 정답을 만족하냐 안하냐에 따라서 구간을 확장(오른쪽을 +1)할지 축소(왼쪽을 -1)할지 결정하는 것이다



### 239. Sliding Window Maximum

sort X
PQ ?
sliding window. 저장구조를 어떻게?
가장 큰 값이 트래킹 되어야 한다

brute force

for left in range(len(nums) - k)
  for right in range(k)


PQ를 쓰면 가장 큰 값은 알 수가 있어
근데 left가 빠져야되는데...

PQ(순차적으로 전부 담는다) + hashmap(left part를 담는다)
PQ에서 가장 큰 값을 꺼낸다.
그 값이 hashmap에 없으면 max 값이다
그 값이 hashmap에 있으면 버리고 다음 값을 쓴다

PQ = { {value, index} }

index가 window 바깥이면 버린다


근데 풀이를 보니 monotone deque 테크닉이 있다. 항상 증가하는 순서로, 단조 방향으로 값이 변하게끔 유지하는 deque이다
어차피 지금 넣는 값은 가장 오래 살아남는다. 따라서 지금 넣는 값보다 작은 값은 다 제거, pop해도 정답에 영향을 미치지 않는다
