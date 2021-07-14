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

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        map<int, vector<int> > graph;
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        map<int, bool> visited;
        vector<int> stack;
        for (map<int, vector<int> >::iterator it = graph.begin(); it != graph.end(); ++it) {
            if (visited[it->first]) {
                continue ;
            }
            dfs(graph, it->first, visited, stack);
        }

        map<int, int> topSortArr;
        int n = stack.size();
        for (int i = n-1; i >= 0; --i) {
            topSortArr[stack[i]] = n - i - 1;
        }

        for (map<int, vector<int> >::iterator it = graph.begin(); it != graph.end(); ++it) {
            for (int i = 0; i < graph[it->first].size(); ++i) {
                if (topSortArr[it->first] > topSortArr[graph[it->first][i]]) {
                    return false;
                }
            }
        }

        return true;
    }

    void dfs(map<int, vector<int> >& graph, int start, map<int, bool>& visited, vector<int>& stack) {
        if (visited[start]) {
            return ;
        }
        visited[start] = true;
        for (int i = 0; i < graph[start].size(); ++i) {
            dfs(graph, graph[start][i], visited, stack);
        }
        stack.push_back(start);
    }
};

int main() {
    vector<vector<int> > v1 { {1, 4}, {2, 4}, {3, 1}, {3, 2} };

    Solution s;
    cout << s.canFinish(5, v1) << endl;

    return 0; 
}
