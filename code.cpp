#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class coordinate {
    int r, c;
public:
    coordinate(int x, int y): r(x), c(y) {}
    int row() { return r; }
    int col() { return c; }
};

int main (int argc, char* argv[]) {
    string dir = argv[1], dir_in, dir_out;
    if(dir=="TA_matrix_1" || dir=="TA_matrix_2" || dir=="TA_matrix_3") {
        dir_in = "test_case/" + dir + ".data";
        dir_out = "test_case/final.peak";
    }
    else {
        dir_in = "test_case/" + dir + "/matrix.data";
        dir_out = "test_case/" + dir + "/final.peak";
    }
    ifstream input(dir_in);
    ofstream output(dir_out);
    /*ifstream input("mat.data");
    ofstream output("final.peak");*/
    int max_row, max_col;
    input >> max_row >> max_col;
    long int row[2][1000];
    int curr = 0, flag[1000];
    vector<coordinate> peaks;

    if(input.is_open() && output.is_open()) {
        for(int j=0; j<max_col; j++) {
            input >> row[0][j];
            flag[j] = 1;
        }
        for(int i=0; i<max_row-1; i++) {
            for(int j=0; j<max_col-1; j++) {
                if(j==0) input >> row[!curr][j];
                input >> row[!curr][j+1];
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
        output << peaks.size() << endl;
        for(auto peak : peaks) output << peak.row() << ' ' << peak.col() << endl;
        input.close();
        output.close();
    }

    else if(!input.is_open()) cout << "Unable to open testcase" << endl;
    else cout << "Unable to open output" << endl;
    return 0;
}