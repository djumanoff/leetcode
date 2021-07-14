#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(), tokens.end());        
        int left = 0;
        int right = tokens.size() - 1;
        int maxScore = 0;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                left++;
                score++;
                maxScore = score;
            } else {
                if (score > 0) {
                    power += tokens[right];
                    right--;
                    score--;
                } else {
                    return maxScore;
                }
            }
        }
        return maxScore;
    }
};

int main() {
    Solution s;
    vector<int> v {100,200,300,400};

    cout << s.bagOfTokensScore(v, 200) << endl;
    return 0;
}
