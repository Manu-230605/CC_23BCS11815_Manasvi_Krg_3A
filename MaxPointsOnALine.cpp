#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Function to calculate GCD
    int getGCD(int a, int b) {
        if(b == 0) return a;
        return getGCD(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        // If points are <= 2, all lie on same line
        if(n <= 2) return n;

        int result = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<string, int> slopeMap;
            int duplicate = 1;  // count the point itself

            for(int j = i + 1; j < n; j++) {

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Case: duplicate points
                if(dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                // Normalize slope using GCD
                int gcd = getGCD(dx, dy);
                dx /= gcd;
                dy /= gcd;

                // Handle sign (important for consistency)
                if(dx < 0) {
                    dx *= -1;
                    dy *= -1;
                } else if(dx == 0) {
                    dy = 1;  // vertical line
                } else if(dy == 0) {
                    dx = 1;  // horizontal line
                }

                string key = to_string(dx) + "/" + to_string(dy);
                slopeMap[key]++;
            }

            int maxPointsOnLine = 0;

            for(auto &it : slopeMap) {
                maxPointsOnLine = max(maxPointsOnLine, it.second);
            }

            result = max(result, maxPointsOnLine + duplicate);
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> points = {{1,1}, {2,2}, {3,3}, {3,4}, {5,6}};
    
    cout << "Maximum points on a line: " 
         << obj.maxPoints(points) << endl;

    return 0;
}