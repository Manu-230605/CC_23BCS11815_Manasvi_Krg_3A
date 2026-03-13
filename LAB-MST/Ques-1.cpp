#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());

    int i = 0, j = tokens.size() - 1;
    int score = 0, maxScore = 0;

    while (i <= j) {
        if (power >= tokens[i]) {
            power -= tokens[i];
            score++;
            i++;
            maxScore = max(maxScore, score);
        }
        else if (score > 0) {
            power += tokens[j];
            score--;
            j--;
        }
        else break;
    }

    return maxScore;
}