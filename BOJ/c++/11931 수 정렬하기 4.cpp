#include <stdlib.h>
#include <vector>
#include <algorithm>

// 이거는 c 스타일의 qsort 를 사용할 때 쓰는 compare
int ascending_Compare(const int value1,const int value2) {
	int iNum1, iNum2;

	iNum1 = value1;
	iNum2 = value2;

	return iNum1 - iNum2;
}
// 이거는 c++ 스타일의 std::sort를 사용할 떄 쓰는 compare
bool compare(const int &i,const int &j){
        return i>j;
}

int main() {

	int N,n;
	std::vector<int> list;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &n);
		list.push_back(n);
	}
	//std::sort(list, N, sizeof(int), ascending_Compare);
	std::sort(list.begin(), list.end(), compare);
	for(int i=0; i<list.size(); i++) {
		printf("%d ", list[i]);
	}


	return 0;
}