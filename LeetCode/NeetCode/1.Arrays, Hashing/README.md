# NeetCode
> https://neetcode.io/practice

## Arrays, Hashing

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

