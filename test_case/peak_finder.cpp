#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct cor
{
    int a, b;
};

int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;

    string id;
    id=argv[1];

    fin.open("./"+id+"/matrix.data");     
    fout.open("./"+id+"/final2.peak");

    if(!fin.is_open())    cout<<"fail"<<endl;


    int row, col,count=0;
    fin>>row>>col;
    long int matrix[row][col];
    cor temp;
    vector<cor> ya;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            fin>>matrix[i][j];
        }
    }

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (i==0)
            {
                if (j==0)
                {
                    if (matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>=matrix[i][j+1])
                    {
                        temp.a=i;
                        temp.b=j;
                        ya.push_back(temp);
                        count++;
                    }
                }
                else if (j==col-1)
                {
                    if (matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>=matrix[i][j-1])
                    {
                        temp.a=i;
                        temp.b=j;
                        ya.push_back(temp);
                        count++;
                    }
                }
                else
                {
                    if (matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>=matrix[i+1][j-1] && matrix[i][j]>=matrix[i][j+1])
                    {
                        temp.a=i;
                        temp.b=j;
                        ya.push_back(temp);
                        count++;
                    }
                }
            }
            else if (i==row-1)
            {
                if (j==0)
                {
                    if (matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>=matrix[i][j+1])
                    {
                        temp.a=i;
                        temp.b=j;
                        ya.push_back(temp);
                        count++;
                    }
                }
                else if (j==col-1)
                {
                    if (matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>=matrix[i][j-1])
                    {
                        temp.a=i;
                        temp.b=j;
                        ya.push_back(temp);
                        count++;
                    }
                }
                else
                {
                    if (matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>=matrix[i][j-1] && matrix[i][j]>=matrix[i][j+1])
                    {
                        temp.a=i;
                        temp.b=j;
                        ya.push_back(temp);
                        count++;
                    }
                }
            }
            else
            {
                if (j==0)
                {
                    if (matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>=matrix[i][j+1])
                    {
                        temp.a=i;
                        temp.b=j;
                        ya.push_back(temp);
                        count++;
                    }
                }
                else if (j==col-1)
                {
                    if (matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>=matrix[i][j-1])
                    {
                        temp.a=i;
                        temp.b=j;
                        ya.push_back(temp);
                        count++;
                    }
                }
                else
                {
                    if (matrix[i][j]>=matrix[i-1][j] && matrix[i][j]>=matrix[i+1][j] && matrix[i][j]>=matrix[i][j-1] && matrix[i][j]>=matrix[i][j+1])
                    {
                        temp.a=i;
                        temp.b=j;
                        ya.push_back(temp);
                        count++;
                    }
                }
            }
        }
    }

    fout<<count<<'\n';
    for (int i=0; i<ya.size(); i++)
    {
        fout<<ya[i].a+1<<" "<<ya[i].b+1<<'\n';
    }

    fin.close();
    fout.close();


    return 0;
}
