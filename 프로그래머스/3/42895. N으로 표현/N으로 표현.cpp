//
//  programmersn.cpp
//  boj1926bfs
//
//  Created by 강명진 on 2020/10/15.
//

#include <bits/stdc++.h>

using namespace std;
int answer =9;
int n;
void dp(int N,int count,int currentNumber){
    if (count>=9)return;
    if (currentNumber==n){
        answer=min(answer,count);
        return;
    }
    int tempNumber=0;
    for (int i =0;i+count<9;i++){
        tempNumber=tempNumber*10+N;
        dp(N,count+1+i,currentNumber+tempNumber);
        dp(N,count+1+i,currentNumber-tempNumber);
        dp(N,count+1+i,currentNumber*tempNumber);
        dp(N,count+1+i,currentNumber/tempNumber);
    }
}
int solution(int N, int number) {
    n=number;
    dp(N,0,0);
    if(answer==9)return -1;
    return answer;
}