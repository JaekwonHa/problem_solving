# NeetCode
> https://neetcode.io/practice

## 1.Arrays, Hashing

### 217. Contains Duplicate 👍

매우 간단한 문제지만, 풀이 방법은 다양하다
python 특성을 사용해서 set으로 변경한 뒤 set과 원래 list의 길이 차를 확인하는 방법을 사용했다

시간 복잡도: N
공간 복잡도: 2N

이 방법은 set을 사용하기 때문에 추가적인 메모리가 필요하다

* 시간을 최적화 하는 방법
  * 모두 set에 담지 않고, empty set을 시작해서 비어있으면 넣고, 이미 있으면 False 반환으로 끝낸다
* 공간을 최적화 하는 방법
  * set을 사용하지 않고 list를 정렬해서 i, i+1을 순차 비교한다

### 242. Valid Anagram

이것도 간단한 문제. 서로 아나그램인지 확인하는 것
여기서는 정렬로 해결했는데..

시간 복잡도: NlogN
공간 복잡도: N

정렬을 사용해서 NlogN이 되었다. N에 해결할 수도 있다

s,t 문자열의 길이를 비교
s의 각 문자가 등장하는 횟수가 t와 일치하는지 비교
`s.count(i) != t.count(i)`

### 1. Two Sum 👍

a = b + c -> a - b = c 로 방정식을 바꿔서 생각해보는 문제이다
b와 c. 두가지 element를 구해야하는 문제에서 a는 고정이기 때문에 c만 구하면 되는 문제로 변환하는 것이다

hash, defaultmap을 사용하면 간단한데, 이 문제에서는 답의 형식이 element의 index다
따라서 index를 어딘가에 저장해두던가 index를 따로 찾던지 해야한다

나는 답을 찾은 뒤 index는 for-loop로 구했다.

시간 복잡도: N * N (하지만 내부 for-loop는 1번만 발생하기 때문에 실질적으로는 N)
공간 복잡도 2N

근데 이 문제에서 정답은 반드시 1개라고 한다
따라서 hash에 어떤 element의 개수가 아니라 index를 저장하고, 그 index가 동일한 숫자, key에 의해서 덮어씌여진다고 해도 상관이 없다
어차피 앞쪽부터 b를 선정하기 때문에 hash에 있는게 자기 자신만 아니라면, 뒤에 덮어쓴 element와 반드시 1개의 정답 쌍을 이룸이 자명하다

### 49. Group Anagrams 👍

아나그램을 판별하는 방법
1. 정렬 후 같은지 비교 NlogN
2. 길이와 각 문자의 등장빈도를 비교. N

이게 이 문제에서는 이런 시간복잡도로 바뀐다
1. N * NlogN * 1
2. N * N * N

시간 복잡도: N^2 * logN
공간 복잡도: 2N

결국 정렬해서 해결하긴 했는데, 답을 보니
정렬해서 비교하는게 아니라 각 element를 순회하면서 문자의 개수를 나타내는 list로 변환 한 뒤 그걸 key로 사용했다.
그러면 N * N * 1 로 가능해진다

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)

        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1
            ans[tuple(count)].append(s)
        return ans.values()
```

### 347. Top K Frequent Elements

딕셔너리에 값을 저장한 뒤, 개수가 많은 순서로 정렬한 뒤 k개를 출력했다.

시간 복잡도: NlogN
공간 복잡도: 2N

이 문제도 '정렬'하지 않고 해결 할 수 있는 방법이 있다
1. heapq를 사용하는 방법. 이 방법은 정렬과 시간 복잡도는 같다. 하지만 '정렬'이라는 것을 힙정렬과 연관지어 생각하는게 중요하다
2. 공간복잡도를 좀 더 써서 빈도수에 대한 해시를 다시 사용하여. N에 해결이 가능하다

freq라는 각각의 index가 빈도수를 나타내는 리스트를 만든다
10th 위치에는 10번 반복된 element들이 있다
뒤에서부터 탐색하면서 k개가 될 때까지 탐색한다

> '정렬'이란 요구사항을 공간복잡도를 좀 더 사용해서, 전처리를 좀 더 써서 해결 할 수 없을지 고민이 필요하다

```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        freq = [[] for i in range(len(nums) + 1)]

        for n in nums:
            count[n] = 1 + count.get(n, 0)
        for n, c in count.items():
            freq[c].append(n)

        res = []
        for i in range(len(freq) - 1, 0, -1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res

        # O(n)
```

### 238. Product of Array Except Self

전체 곱을 유지하는 int 변수 하나를 두고, 전체 배열에서 0의 개수와 현재 값이 0인지 아닌지에 따라서 0을 채우거나 전체 곱에서 자기자신을 나눠주거나 하는 방법을 사용했다

시간 복잡도: N
공간 복잡도: 1

문제의 요구사항은 만족했다고 생각한다.
다만 이 문제를 좀 더 단계적으로 접근해본다면 left / right 부분곱 배열을 두는 방법을 생각해볼 수 있다
이는 추가적인 배열을 유지해야하므로 공간 복잡도가 커진다

다음으로 answer 배열을 사용해서(이건 카운팅 안되므로) left 배열로 사용하고,
한번 더 뒤에서부터 돌면서 right 변수(리스트가 아닌 int)를 바로바로 만들어 가면서 사용하는 방법.
마치 two sum에서 두 가지 변수를 탐색하는게 아니라 전처리를 통해서 한 가지 변수를 bigO(1)에 찾는 문제로 변형하는 듯이 해결할 수 있다

### 271. Encode and Decode Strings

List<str> -> str -> List<str> 순서로 인코딩, 디코딩할 수 있는 알고리즘을 작성하는 것

순서가 유지되어야 하고, 구분자로 각 element를 구분할 수 있어야 한다
일단 구분자를 무엇으로 할 것 인지가 가장 관건이다

1. 아스키 문자가 아닌 것을 구분자로 사용한다. ex. 이모지 👍 혹은 `unichr(258)`

혹은... 문자열 1개당 최대 길이가 200자니깐. 201자짜리 구분자를 사용?

이모지를 사용해서 해결하긴 했지만, 솔루션에서는 Chunked Transfer Encoding 방식을 소개한다
구분자에 다음에 오는 element의 길이를 남긴다

그래서 항상 가장 먼저는 element의 길이가 오고, 그만큼만 읽었다가 다시 구분자와 length를 읽는다

### 128. Longest Consecutive Sequence

정렬되지 않은 int list 에서 연속적인 element의 최대 길이를 구하는 문제이다
정렬로 해결하면 쉽게 해결할 수 있지만, 문제에서는 O(N)을 요구한다

이 문제도 단계별로 사고의 발전을 보여주기 괜찮은 문제같다

brute force로 해결한다고 해보자
ith 위치에서 그 뒤로 연속적인 숫자가 있는지 쭉 확인한다
시간복잡도는 N^2 이다

sort 하게되면 NlogN 일테고..

여기서 hash O(1)을 사용한다면?
brute force 방법과 유사하게..자신과 연속되는 숫자가 있는지 없는지를 dictionary를 사용한다면 O(1)에 조회가 가능하다
근데 downside, upside 모두 확인해야할텐데, 항상 연속적인 숫자의 첫번째. 자기보다 1 작은 숫자가 없는 element에서만 출발한다면 O(N)만에 해결이 가능하다
