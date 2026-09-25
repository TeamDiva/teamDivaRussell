//
//  programmersLongNode.cpp
//  boj1926bfs
//
//  Created by 강명진 on 2020/10/31.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> graph[20001];

int check[20001];

void bfs(int x){
    queue<int> q;
    check[x]=1;
    q.push(x);
    while(!q.empty()){
        int now=q.front();q.pop();
        for (int dir = 0 ; dir<graph[now].size();dir++){
            int nx=graph[now][dir];
            if (check[nx]>0)continue;
            check[nx]=check[now]+1;
            q.push(nx);
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    N=n;
    for (auto i : edge){
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    bfs(1);
    int ans=0;
    for (int i = 1 ; i <= n;i++){
        if (ans<check[i])ans=check[i];
    }
    int count=0;
    for (int i = 1 ; i <= n;i++){
        if (ans==check[i])count++;
    }
    return count;
}