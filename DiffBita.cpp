#include <iostream>
#include <vector>
using namespace std;

int totalDifferentBits(vector<int>& arr) {
    int n = arr.size();
    long long total = 0;

    for (int bit = 0; bit < 32; bit++) {
        int count1 = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] & (1 << bit))
                count1++;
        }

        int count0 = n - count1;
        total += (long long)count1 * count0 * 2;
    }

    return total;
}

int main() {
    vector<int> arr1 = {1, 3, 5};
    cout << totalDifferentBits(arr1) << endl; // 8

    vector<int> arr2 = {2, 3};
    cout << totalDifferentBits(arr2) << endl; // 2

    return 0;
}
