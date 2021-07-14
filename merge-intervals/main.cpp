#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vec(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_2dvec(vector<vector<int> > v) {
    for (int i = 0; i < v.size(); i++) {
        print_vec(v[i]);
    }
    cout << endl;
};

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        qsort(intervals, 0, intervals.size()-1);
        vector<vector<int> > result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> t1 = result[result.size()-1];
            vector<int> t2 = intervals[i];
            if (t1[1] < t2[0]) {
                result.push_back(t2);
            } else {
                vector<int> t3;
                t3.push_back(t1[0]);
                if (t2[1] > t1[1]) {
                    t3.push_back(t2[1]);
                } else {
                    t3.push_back(t1[1]);
                }
                result.pop_back();
                result.push_back(t3);
            }
        }

        return result;
    }

private:
    void qsort(vector<vector<int> >& intervals, int i, int j) {
        if (j - i <= 0) {
            return ;
        }
        int pi = (i + j)/2;
        int left = i;
        int right = j;
        swap(intervals, pi, right);
        for (int l = i; l < j; l++) {
            if (intervals[l][0] < intervals[right][0]) {
                swap(intervals, l, left);
                left++;
            }
        }
        swap(intervals, left, right);

        qsort(intervals, i, left);
        qsort(intervals, left+1, right);
    }
    
    void swap(vector<vector<int> >& intervals, int i, int j) {
        vector<int> t = intervals[i];
        intervals[i] = intervals[j];
        intervals[j] = t;
    }
};


int main() {
    Solution s;
    // vector<vector<int> > v;
    // vector<int> r1 {1, 3};
    // vector<int> r2 {2, 6};
    // vector<int> r3 {8, 10};
    // vector<int> r4 {15, 18};

    // v.push_back(r3);
    // v.push_back(r2);
    // v.push_back(r1);
    // v.push_back(r4);
    // s.merge(v);

    vector<vector<int> > v;
    vector<int> r1 {1, 4};
    vector<int> r2 {4, 5};

    v.push_back(r1);
    v.push_back(r2);
    s.merge(v);

    print_2dvec(s.merge(v));
    return 0;
}
