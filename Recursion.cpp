#include<iostream>
using namespace std;

void displayArrayUsingRecursion(int list[], int size, int idx){
    if(idx == size){
        return;
    }

    cout<<list[idx]<<" | ";

    displayArrayUsingRecursion(list, size, idx + 1);
}

int sumArrayUsingRecursion(int list[], int size, int idx){
    if(idx == size){
        return 0;
    }

    return list[idx] + sumArrayUsingRecursion(list, size, idx + 1);
}

int main(){

}