//
//  P82_InterestingParty.cpp
//  TopCoderBook
//
//  Created by jaekwon ha on 2018. 1. 3..
//  Copyright © 2018년 jaekwon ha. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    
    freopen("/Users/jaekwonha/workspace/TopCoderBook/C++/TopCoderBook/res/P82_InterestingParty.txt", "r", stdin);

    int N;
    map<string, int> m1, m2;
    string str;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        cin>>str;
        m1[str]++;
    }
    for(int i=0; i<N; i++) {
        cin>>str;
        m1[str]++;
    }
    int answer=0;
    for (pair<string,int> a : m1)
        answer = max(answer, a.second);
    
    printf("%d\n", answer);
        
    return 0;
}
