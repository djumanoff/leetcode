#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        permute(candidates, curr, 0, target);
        
        return result;
    }
    
    void permute(vector<int> candidates, vector<int> curr, int sum, int target) {
        if (sum > target) {
            return ;
        }
        if (sum == target) {
            result.push_back(curr);
            return ;
        }
        int num = 0;
        while (!candidates.empty()) {
            if (num == candidates.back()) continue;
            num = candidates.back();
            curr.push_back(num);
            candidates.pop_back();
            permute(candidates, curr, sum + num, target);
            curr.pop_back();
        }
    }
};


int main() {
    return 0;
}
