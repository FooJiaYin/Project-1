#include <iostream>
#include <vector>
using namespace std;

class coordinate {
    int r, c;
public:
    coordinate(int x, int y): r(x), c(y) {}
    int row() { return r; }
    int col() { return c; }
};

int main (void) {
    int max_row, max_col;
    cin >> max_row >> max_col;
    long int row[2][1000];
    int curr = 0, flag[1000];
    vector<coordinate> peaks;

    for(int j=0; j<max_col; j++) {
        cin >> row[0][j];
        flag[j] = 1;
    }
    for(int i=0; i<max_row-1; i++) {
        for(int j=0; j<max_col-1; j++) {
            if(j==0) cin >> row[!curr][j];
            cin >> row[!curr][j+1];
            if(row[curr][j] >= row[curr][j+1]) {
                if(flag[j] && (row[curr][j] >= row[!curr][j])) {
                    peaks.push_back(coordinate(i, j));
                //    cout << i << ' ' << j << endl;
                }
            }
            flag[j+1] = flag[j+1] && (row[curr][j] <= row[curr][j+1]); 
            flag[j] = (row[curr][j] <= row[!curr][j]); 
        }
        if(flag[max_col-1] && (row[curr][max_col-1] >= row[!curr][max_col-1])) peaks.push_back(coordinate(i, max_col-1)); 
        flag[max_col-1] = (row[curr][max_col-1] >= row[!curr][max_col-1]); 
        curr = !curr;
    }
    for(int j=0; j<max_col-1; j++) {
        if(flag[j] && (row[curr][j] >= row[curr][j+1])) {
            peaks.push_back(coordinate(max_row-1, j));
        //    cout << max_row-1 << ' ' << j << endl;
        }
        flag[j+1] = (row[curr][j] <= row[curr][j+1]); 
    }
    if(flag[max_col-1]) peaks.push_back(coordinate(max_row-1, max_col-1));

    cout << peaks.size() << endl;
    for(auto peak : peaks) cout << peak.row() << ' ' << peak.col() << endl;

    return 0;
}