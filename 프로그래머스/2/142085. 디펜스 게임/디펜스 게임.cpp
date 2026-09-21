#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool canClear(int mid, int n, int k, const vector<int>& enemy){
    vector<int> temp(enemy.begin(),enemy.begin()+mid);
    
    sort(temp.rbegin(),temp.rend());
    
    long long required_soldiers = 0;
    for (int i =k;i<temp.size();i++){
        required_soldiers+=temp[i];
    }
    return required_soldiers<=n;
}

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    if (k>=enemy.size()) return enemy.size();
    
    int low = 1;
    int high = enemy.size();
    while (low <= high){
        int mid = low + (high-low)/2;
        if (canClear(mid,n,k,enemy)){
            answer = mid;
            low = mid + 1;
        }else{
            high = mid-1;
        }
    }
    return answer;
}