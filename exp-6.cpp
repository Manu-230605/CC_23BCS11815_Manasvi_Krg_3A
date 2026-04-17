#include <bits/stdc++.h>
using namespace std;

class BIT {
    vector<int> tree;
    int n;

public:
    BIT(int n) {
        this->n = n;
        tree.resize(n + 1, 0);
    }
    void update(int i, int value) {
        while (i <= n) {
            tree[i] += value;
            i += i & (-i);
        }
    }
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5}; 
    int n = arr.size() -1;

    BIT bit(n);

    for (int i = 1; i <= n; i++) {
        bit.update(i, arr[i]);
    }

    cout << "Sum [2 to 5]: " << bit.rangeQuery(2, 5) << endl;
    bit.update(3, 5);

    cout << "After update, Sum from 2 to 5: "
         << bit.rangeQuery(2, 5) << endl;

    return 0;
}