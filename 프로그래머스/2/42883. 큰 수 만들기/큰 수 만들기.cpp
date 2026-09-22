#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (auto c:number){
        while(!answer.empty()&&k>0&&answer.back()<c){
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }
    if (k>0){
        answer.erase(answer.length()-k);
    }
    return answer;
}