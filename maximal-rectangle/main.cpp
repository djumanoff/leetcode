#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.size() <= 0) {
            return 0;
        }
        int maxArea = 0;
        vector<int> hist(matrix[0].size());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') {
                    hist[j] += 1;
                } else {
                    hist[j] = 0;
                }
            }
            int area = maxAreaOfHist(hist);
            if (area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }

    int maxAreaOfHist(vector<int> hist) {
        vector<int> st;
        int maxArea = 0;
        int n = hist.size();
        int i = 0;
        for (; i < n;) {
            if (st.empty() || hist[i] >= hist[st.back()]) {
                st.push_back(i++);
            } else {
                int top = st.back();
                st.pop_back();
                int area = 0;
                if (st.empty()) {
                    area = hist[top] * i;
                } else {
                    area = hist[top] * (i - st.back() - 1);
                }
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }

        while (!st.empty()) {
            int top = st.back();
            st.pop_back();
            int area = 0;
            if (st.empty()) {
                area = hist[top] * i;
            } else {
                area = hist[top] * (i - st.back() - 1);
            }
            if (area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
};

int main() {
    Solution s;

    vector<vector<char> > matrix { 
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    cout << s.maximalRectangle(matrix) << endl;

    return 0;
}
