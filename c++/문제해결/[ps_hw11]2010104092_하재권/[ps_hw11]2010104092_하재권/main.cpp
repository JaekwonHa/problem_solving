#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct eData {
    int num;
    int weight;
    int iq;
};

eData elephant[1000];

int dp[1000];
int from[1000];

int elecompare(const void *cmp1, const void *cmp2){
	eData* c1 = (eData*)cmp1;
	eData* c2 = (eData*)cmp2;
    if((eData*)c1->weight == (eData*)c2->weight)
        return c1->iq - c2->iq;
    return c1->weight - c2->weight;
}

void dpprint(int idx){
    if(idx == -1) return ;
    dpprint(from[idx]);
	cout<<elephant[idx].num<<endl;
}

int main(){
    int eleidx = 0;
    int i, j, maxidx, max = -1;

	while(cin>>elephant[eleidx].weight>>elephant[eleidx].iq) {
		if(elephant[eleidx].weight == EOF || elephant[eleidx].iq == EOF) break;
        elephant[eleidx].num = eleidx+1;
        eleidx++;
    }

    qsort(elephant, eleidx, sizeof(eData), elecompare);

    for(i = 0 ; i < eleidx ; i++){
        dp[i] = 1;
        from[i] = -1;
        for(j = 0 ; j < i ; j++){
            if(elephant[i].iq < elephant[j].iq
                    && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                from[i] = j;
                if(max < dp[i]){
                    max = dp[i];
                    maxidx = i;
                }
            }
        }
    }

    cout<<max<<endl;
    dpprint(maxidx);
    return 0;
}