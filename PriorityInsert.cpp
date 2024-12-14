#include<iostream>
using namespace std;

int priorityInsert(int array[], int size, int elements, int value){

    if(elements >= size){
        return elements;
    }

    int i;

    for(i = size - 1 ; i >= 0 && array[i] < value ; i-- ){
        array[i + 1] = array[i];
    }

    array[i + 1] = value;
    elements++;
    return elements;
}

int main(){

}