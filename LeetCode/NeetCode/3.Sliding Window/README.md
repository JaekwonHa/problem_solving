## 3.Sliding Window

left, right 쓰는 것은 Two Pointer와 유사
window 내부의 element 들을 저장하는 dict 정도를 사용하는 트릭이 필요


### 424. Longest Repeating Character Replacement

앞에서부터 순차적으로 봐야하는데, 어떠한 window, 구간은 현재 element가 기준이 아니라 현재 element를 교체해야하는 경우도 있다.
따라서 기준을 그렇게 잡으면 안되고..

지금 element와 기존에 파악하고 있던 가장 많이 등장한 문자 개수와 비교하여 더 큰 것을 기준으로 하고 나머지를 다 교체한다고 생각해야한다
(greedy)

그래서 전체 window 길이에서 가장 많이 등장한 문자 개수를 빼면 현재 window에서 교체를 진행한 횟수를 알 수 있다









