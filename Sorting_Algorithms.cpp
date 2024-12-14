#include <iostream>
using namespace std;

void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void insertionSort(int array[], int size){
    for(int i = 1 ; i < size ; i++){
        int current = array[i];
        int j = i - 1;
        
        while(j >= 0 && array[j] > current){
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = current;
    }
}

int main()
{
    int size;
    cout << "Enter The Size Of The Array : ";
    cin >> size;

    int *Numbers = new int[size];

    cout << "\n\nEnter The Elements Of The Array : " << endl << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Element : ";
        cin >> Numbers[i];
    }

    cout << "\nOriginal array: ";
    displayArray(Numbers, size);

    bubbleSort(Numbers, size);
    cout << "\nArray after Bubble Sort: " << endl << endl;
    displayArray(Numbers, size);

    // Reset the array to its original state for selection sort
    cout << "\nRe-enter the elements of the array for Selection Sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> Numbers[i];
    }

    selectionSort(Numbers, size);
    cout << "\nArray after Selection Sort: " << endl << endl;
    displayArray(Numbers, size);
}