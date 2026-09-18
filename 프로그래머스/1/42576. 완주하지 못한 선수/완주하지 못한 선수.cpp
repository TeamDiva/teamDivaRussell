#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> um;
    for (auto name : participant){
        um[name]++;
    }
    for (auto name : completion){
        um[name]--;
    }
    for (auto now : um){
        if (now.second > 0){
            return now.first;
        }
    }
    return answer;
}