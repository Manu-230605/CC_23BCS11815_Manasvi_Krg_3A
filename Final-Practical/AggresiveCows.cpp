#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int k, int minDist) {
    int cows = 1; 
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDist) {
            cows++;
            lastPos = stalls[i];
        }
        if (cows >= k) return true;
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            ans = mid;        
            low = mid + 1;
        } else {
            high = mid - 1;   
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout<<aggressiveCows(stalls , k);
    return 0;
}