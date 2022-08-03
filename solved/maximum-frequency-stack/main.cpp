#include <map>
#include <vector> 
#include <iostream> 

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

class FreqStack {
    map<int, vector<int> > freqMap;
    map<int, int> freq;
    int maxFreq;
    
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        if (freq[val] > maxFreq) {
            maxFreq = freq[val];
        }
        freqMap[freq[val]].push_back(val);
    }
    
    int pop() {
        int val = freqMap[maxFreq][freqMap[maxFreq].size()-1];
        freqMap[maxFreq].pop_back();
        freq[val]--;
        if (freqMap[maxFreq].size() == 0) {
            maxFreq--;
        }
        return val;
    }
};

int main() {
    FreqStack fs;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);

    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;

    return 0;
}
