#include <string>
#include <vector>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool isEquals(string a,string b){
    if (a.size()!=b.size()){
        return false;
    }
    for (int i = 0;i<a.size();i++){
        if (a[i]!=b[i])return false;
    }
    return true;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string now = board[h][w];
    for (int i =0;i<4;i++){
        int nx = h+dx[i];
        int ny = w+dy[i];
        if (nx<0||nx>=board.size()||ny<0||ny>=board[0].size()){
            continue;
        }
        string next = board[nx][ny];
        if (isEquals(now,next)){
            answer++;
        }
    }
    return answer;
}