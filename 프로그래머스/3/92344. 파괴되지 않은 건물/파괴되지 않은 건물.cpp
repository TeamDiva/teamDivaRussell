#include <string>
#include <vector>

using namespace std;
int delta[1001][1001];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int R = board.size(), C = board[0].size();

    for (int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];

        degree = (type == 1) ? -degree : degree; // ✅ 주의: type==1이면 파괴 → 감소

        // ✅ 정확한 누적합 갱신
        delta[r1][c1] += degree;
        delta[r1][c2 + 1] -= degree;
        delta[r2 + 1][c1] -= degree;
        delta[r2 + 1][c2 + 1] += degree;
    }

    // 좌→우 누적합
    for (int i = 0; i < R; i++) {
        for (int j = 1; j < C; j++) {
            delta[i][j] += delta[i][j - 1];
        }
    }

    // 위→아래 누적합
    for (int j = 0; j < C; j++) {
        for (int i = 1; i < R; i++) {
            delta[i][j] += delta[i - 1][j];
        }
    }

    // 결과 계산
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] + delta[i][j] > 0) {
                answer++;
            }
        }
    }

    return answer;
}