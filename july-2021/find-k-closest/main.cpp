#include <vector>
#include <iostream>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = arr.size();
        if (n == k) {
            return arr;
        }
        
        vector<int> ans;
        int idx = getIndex(arr, 0, n - 1, x);
        int l = idx;
        int r = idx;

        while (r - l < k) {
            if (l == 0) {
                r++;
                continue;
            }
            if (r == n) {
                l--;
                continue;
            }
            int diffLeft = abs(arr[l-1] - x);
            int diffRight = abs(arr[r] - x);

            if (diffLeft <= diffRight) {
                l--;
            } else {
                r++;
            }
        }

        cout << l << " " << r << endl; 

        while (l < r) {            
            ans.push_back(arr[l]);            
            l++;
        }

        return ans;
    }
    
    int getIndex(vector<int>& arr, int l, int r, int x) {
        if (r - l <= 1) {
            return abs(arr[l] - x) <= abs(arr[r] - x) ? l : r;
        }
        int m = (l + r)/2;
        if (arr[m] > x) {
            return getIndex(arr, l, m, x);
        } else if (arr[m] < x) {
            return getIndex(arr, m, r, x);
        }
        return m;
    }
};

int main() {
    Solution s;
    vector<int> v {-2,-1,1,2,3,4,5};
    print_arr(s.findClosestElements(v, 7, 3));

    vector<int> v1 {1};
    print_arr(s.findClosestElements(v1, 1, 1));

    vector<int> v2 {1,2,3,4,5};
    print_arr(s.findClosestElements(v2, 4, -1));

    vector<int> v3 {0,1,1,1,2,3,6,7,8,9};
    print_arr(s.findClosestElements(v3, 9, 4));
    
    vector<int> v4 {1,1,1,10,10,10};
    print_arr(s.findClosestElements(v4, 1, 9));
    
    vector<int> v5 {0,0,0,1,3,5,6,7,8,8};
    print_arr(s.findClosestElements(v5, 2, 2));

    vector<int> v6 {0,1,2,2,2,3,6,8,8,9};
    print_arr(s.findClosestElements(v6, 5, 9));

    return 0;
}
