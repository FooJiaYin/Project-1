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

    int max_row, max_col;
    input >> max_row >> max_col;
    long int row[2][1000];
    int curr = 0;
    int prob[1000];           //probability of a point to become peak
    vector<coordinate> peaks; //store the peaks

    if(input.is_open() && output.is_open()) {
        /* Read the first row */
        for(int j=0; j<max_col; j++) {
            input >> row[0][j];
            prob[j] = 1;
        }
        for(int i=0; i<max_row-1; i++) {
            for(int j=0; j<max_col-1; j++) {
                /* Read the next row */
                if(j==0) input >> row[!curr][j]; 
                input >> row[!curr][j+1];  
                /* Comparing */
                if(row[curr][j] >= row[curr][j+1]) {                    //compare with its right
                    if(prob[j] && (row[curr][j] >= row[!curr][j])) {    //compare with its down
                        peaks.push_back(coordinate(i, j));
                    }
                }
                prob[j+1] = prob[j+1] && (row[curr][j] <= row[curr][j+1]); //set prob of its right
                prob[j] = (row[curr][j] <= row[!curr][j]);                 //set prob of its down
            }
            /* Last col of the row */
            if(prob[max_col-1] && (row[curr][max_col-1] >= row[!curr][max_col-1]))  //compare with its down
                peaks.push_back(coordinate(i, max_col-1)); 
            prob[max_col-1] = (row[curr][max_col-1] <= row[!curr][max_col-1]);      //set prob of its down
            curr = !curr;
        }
        /* Last row */
        for(int j=0; j<max_col-1; j++) {
            if(prob[j] && (row[curr][j] >= row[curr][j+1])) {   //compare with its right
                peaks.push_back(coordinate(max_row-1, j));
            }
            prob[j+1] = (row[curr][j] <= row[curr][j+1]);       //set prob of its right
        }
        /* Last point */
        if(prob[max_col-1]) peaks.push_back(coordinate(max_row-1, max_col-1));

        output << peaks.size() << endl;
        for(auto peak : peaks) output << peak.row() << ' ' << peak.col() << endl;
        input.close();
        output.close();
    }

    else if(!input.is_open()) cout << "Unable to open testcase" << endl;
    else cout << "Unable to open output" << endl;
    return 0;
}