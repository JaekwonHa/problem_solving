//
//  main.cpp
//  TopCoderBook
//
//  Created by jaekwon ha on 2017. 12. 31..
//  Copyright © 2017년 jaekwon ha. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> capacities, bottles, toId, fromId;
    
    int N,M;
    
    freopen("/Users/jaekwonha/workspace/TopCoderBook/C++/TopCoderBook/res/P65_KiwiJuiceEasy.txt", "r", stdin);

    cin>>N;
    capacities.resize(N);
    bottles.resize(N);
    
    for(int i=0; i<N; i++) cin>>capacities[i];
    for(int i=0; i<N; i++) cin>>bottles[i];
    
    cin>>M;
    fromId.resize(M);
    toId.resize(M);
    for(int i=0; i<M; i++) cin>>fromId[i];
    for(int i=0; i<M; i++) cin>>toId[i];

    for(int i=0; i<M; i++) {
        int f = fromId[i];
        int t = toId[i];
        
        int sum = bottles[f] + bottles[t];
        bottles[t] = min(sum, capacities[t]);
        bottles[f] = sum - bottles[t];
    }
    
    for(int bottle : bottles) {
        cout<<bottle<<" ";
    }
    
    return 0;
}
