#include <vector> 

using namespace std;

class MineSweeper {
private:
    vector<vector<int> > field;
    int numOfMines;
    int numOfRows;
    int numOfCols;

public:

    MineSweeper(int _numOfMines, int rows, int cols) {
        numOfMines = _numOfMines;
        numOfRows = rows;
        numOfCols = cols;
    }

    void generateMineField() {

    }
};
