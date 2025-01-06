#include <iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Copy data to temp arrays first[] and second[]
    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrIdx = start;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrIdx++];
    }

    mainArrIdx = mid + 1;

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrIdx++];
    }

    // Merge 2 Sorted Arrays
    int idx1 = 0;
    int idx2 = 0;
    int idxmain = start;

    while (idx1 < len1 && idx2 < len2)
    {
        if (first[idx1] < second[idx2])
        {
            arr[idxmain++] = first[idx1++];
        }
        else
        {
            arr[idxmain++] = second[idx2++];
        }
    }

    while (idx1 < len1)
    {
        arr[idxmain++] = first[idx1++];
    }

    while (idx2 < len2)
    {
        arr[idxmain++] = second[idx2++];
    }
}

void mergeSort(int arr[], int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);

    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};

    int size = 5;

    mergeSort(arr, 0, size - 1);
}