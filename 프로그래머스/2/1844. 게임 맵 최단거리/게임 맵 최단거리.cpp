#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
int visited[101][101];
int board[101][101];
int bfs(){
    queue<pair<int,int>> q;
    visited[0][0]=1;
    q.push({0,0});
    while(!q.empty()){
        auto now = q.front();q.pop();
        int x=now.first;
        int y=now.second;
        for (int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if (nx < 0 ||nx>=n||ny<0||ny>=m)continue;
            if (visited[nx][ny]>0||board[nx][ny]==0)continue;
            visited[nx][ny]=visited[x][y]+1;
            q.push({nx,ny});
            if (nx==n-1&&ny==m-1)return visited[nx][ny];
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n=maps.size();
    m=maps[0].size();
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            board[i][j]=maps[i][j];
        }
    }
    answer=bfs();
    return answer;
}