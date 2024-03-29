# day4. 동적 계획법(Dynamic Programming)


완전 탐색 문제에서 반복되는 탐색 지점이 존재할때 반복되는 탐색 지점의 탐색 결과를 캐싱 (메모이제이션) 해두어 반복 탐색을 제거 합니다 (가지치기)

주어진 문제를 여러 개의 부분 문제들로 나누어 푼 다음, 겹치는 부분 문제들은 저장해두고 사용합니다.


재귀 호출 = 탑다운
반복문 = 바텀업


이진수, 타일, 스티커, 동전, 배낭 등등 다양한 문제가 존재



## 11051번: 이항 계수 2

이항계수(Binomial Coefficient)는 조합론에서 등장하는 개념으로 주어진 크기 집합에서 원하는 개수만큼 순서없이 뽑는 조합의 가짓수를 일컫는다. 2를 상징하는 ‘이항’이라는 말이 붙은 이유는 하나의 아이템에 대해서는 ‘뽑거나, 안 뽑거나’ 두 가지의 선택만이 있기 때문이다.

nCr = n-1Cr-1 + n-1Cr

위의 점화식이 잘 성립하는지 다음의 예시를 통해 확인해 보도록 하겠습니다. 다음과 같이 원소가 { 1, 2, 3, 4 } 인 집합에서 3개를 뽑는 상황을 가정하겠습니다. 이를 식으로 표현하면 4C3 으로 표현할 수 있습니다.

 

위의 상황에서 먼저 원소 1에 대한 선택 여부를 고려한다고 했을 때 다음과 같이 두가지 상황으로 나뉘어집니다.
* 원소 1를 선택 한 경우 : 나머지 3개 중에서 2개를 선택 
	- 3C2
* 원소 1을 선택하지 않은 경우 : 나머지 3개 중에서 3개를 선택 
	- 3C3

각각의 경우의 수를 더한 결과가 4C3 의 모든 경우가 되므로 

4C3 = 3C2 + 3C3 으로 표현할 수 있고 위의 점화식이 잘 성립함을 알 수 있습니다. 



## 12865번: 평범한 배낭
> 0-1 냅색 문제

D{N}{K} = max (D{N-1}{K-weight}+value, D{N-1}{K})

처음에는 이전 문제들처럼 K. 무게를 1~K까지 증가시키면서 각 무게 K 에서의 최대 value를 구하려고 했다
아이템을 1개만 사용할 수 있으니 visit 체크도 했는데...

이 문제는 N. 아이템 기준으로 먼저 for-loop를 수행해야 한다
워낙 유명한 문제니깐 그냥 이렇게 외워두자

D{N}{K} = 아이템 N번째 까지 선택해봤을때 무게 K 이내에서 가장 높은 value

```go
	for i := 1; i <= N; i++ {
		for j := 1; j <= K; j++ {
			if j-weight[i] >= 0 {
				cache[i][j] = max(cache[i-1][j], cache[i-1][j-weight[i]]+value[i])
			} else {
				cache[i][j] = cache[i-1][j]
			}
		}
	}
```

## 11055번: 가장 큰 증가 부분 수열

i번쨰 아이템을 선택한다 / 선택안한다

DP[i] = i번째 아이템을 선택했을때 가장 큰 증가 부분 수열의 합
최종 답은 DP 배열의 가장 큰 값이 된다

i번째 아이템을 선택했을때, 이전 아이템들 중 선택할 수 있는게 제한이 되는데,
그 중에서 가능한 아이템들을 선택했을때 가장 큰 값 + i번째 아이템의 가치가 답이 된다

이때 이전 아이템들중 가능한 것들은 모두다 비교를 해봐야 한다


```go
	for i := 2; i <= N; i++ {
		var j int
		for j = i - 1; j > 0; j-- {
			if numbers[j] < numbers[i] {
				cache[i] = max(cache[i], cache[j]+numbers[i])
			}
		}
	}
```








