#include <iostream>
using namespace std;

void Traversal2DString(string array[5][3], int row, int col){
    if(row >= 5){
        return;
    }

    if(col >= 3){
        Traversal2DString(array, row + 1 , 0);
        return;
    }

    cout<<array[row][col]<<"  ";
    Traversal2DString(array, row , col + 1);
}

int main()
{
    string array[5][3] = {
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"}
    };

    Traversal2DString(array, 0, 0);
}