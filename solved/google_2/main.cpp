#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

int volumeOfLakes(vector<int> bars) {
    int n = bars.size();
    int totalWater = 0;

    vector<int> leftMax(n);
    vector<int> rightMax(n);
    leftMax[0] = bars[0];
    rightMax[n-1] = bars[n-1];

    for (int i = 1; i < n; i++) {
        if (bars[i] >= leftMax[i-1]) {
            leftMax[i] = bars[i];
        } else {
            leftMax[i] = leftMax[i-1];
        }
    }

    for (int i = n-2; i >= 0; i--) {
        if (bars[i] >= rightMax[i+1]) {
            rightMax[i] = bars[i];
        } else {
            rightMax[i] = rightMax[i+1];
        }
    }

    for (int i = 1; i < n-1; i++) {
        totalWater += min(leftMax[i], rightMax[i]) - bars[i];
    }

    return totalWater;
};

int min(int a, int b) {
    return a > b ? b : a;
}

int main() {
    vector<int> v1 {1,3,2,4,1,3,1,4,5,2,2,1,4,2,2};
    cout << volumeOfLakes(v1) << endl;
    return 0;
}
