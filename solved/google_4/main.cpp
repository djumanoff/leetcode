#include <vector>
#include <string>

using namespace std;

bool isSquare(vector<string> words) {
    bool result = true;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            if (words[i][j] != words[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    return 0;
}
