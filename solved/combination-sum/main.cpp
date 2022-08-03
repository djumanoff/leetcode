#include <vector>
#include <iostream> 

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_2darr(vector<vector<int> > v) {
    for (int i = 0; i < v.size(); i++) {
        print_arr(v[i]);
    }
    cout << endl;
};

class Solution {
public:
    vector<vector<int> > answer;

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        findAll(candidates, 0, curr, 0, target);

        return answer;
    }

    void findAll(vector<int>& candidates, int start, vector<int> curr, int currSum, int target) {
        if (currSum > target) {
            return ;
        }
        if (currSum == target) {
            answer.push_back(curr);
            return ;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (currSum + candidates[i] <= target) {
                curr.push_back(candidates[i]);
                findAll(candidates, i, curr, currSum + candidates[i], target);
                curr.pop_back();
            }
        }
    }
};

int main() {
    Solution s;

    vector<int> v {2, 3, 6, 7};
    print_2darr(s.combinationSum(v, 7));

    return 0;
}
