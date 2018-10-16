#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("./106000105/matrix.data");
    fout<<"1000"<<"1000"<<endl;
    for (int i=0; i<1000; i++)
    {
        for (int j=0; j<1000; j++)
        {
            if (j==999) fout<<"0"<<endl;
            else    fout<<"0"<<" ";
        }
    }
    fout.close();

    return 0;
}
