#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

void print_arr(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

class Solution {
public:
    vector<string>v;
    vector<string> generateParenthesis(int n) {
        findAll("(",1,0,n);
        return v;
    }
    void findAll(string curr,int op,int cl,int n)
    {
        if(op==n && cl==n)
            v.push_back(curr);
        if(op < n)
            findAll(curr+"(",op+1,cl,n);
        if(cl < op)
            findAll(curr+")",op,cl+1,n);
    }
};

int main() {
    Solution s;
    print_arr(s.generateParenthesis(4));
    return 0;
}
