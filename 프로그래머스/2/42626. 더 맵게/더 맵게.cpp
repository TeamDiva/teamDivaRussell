#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    int N = scoville.size()-1;
    for (auto i : scoville) {
        pq.push(-i);
    }
    while (-pq.top()<K) {
        if (pq.size()<2) {
            return -1;
        }

        int first = -pq.top();
        pq.pop();

        int second = -pq.top();
        pq.pop();

        int scov = first+second*2;
        pq.push(-scov);
        answer ++;
    }
    return answer;
}