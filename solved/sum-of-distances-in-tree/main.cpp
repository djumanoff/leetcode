#include <iostream>
#include <vector>
#include <map>

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
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int> > graph(n);

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        print_2darr(graph);

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = dfs(graph, i, i);
        }

        print_arr(result);

        return result;
    }

    int dfs(vector<vector<int> >& graph, int parent, int current) {
        if (graph[current].empty()) {
            return 0;
        }
        if (graph[current].size() == 1 && graph[current][0] == parent && current != parent) {
            return 0;
        }
        cout << parent << " " << current << endl;
        int dist = 0;
        for (int i = 0; i < graph[current].size(); i++) {
            if (parent == graph[current][i]) continue;
            dist += 1 + dfs(graph, current, graph[current][i]);
        }
        return dist;
    }
};

int main() {
    Solution s;

    // 1 2
    // 0
    // 0 3 4 5
    // 2
    // 2
    // 2
    vector<vector<int> > v {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    s.sumOfDistancesInTree(6, v);

    return 0;
}
