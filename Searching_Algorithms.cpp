#include <iostream>
using namespace std;

int LinearSearch(int list[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == target)
        {
            cout << "\n\nThe Target Element Is Found At " << i << " Index" << endl;
            return i;
        }
    }

    cout << "\n\nThe Target Element Is Not Found In The List" << endl;
    return -1;
}

int BinarySearch(int list[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int mid = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (list[mid] < target)
        {
            low = mid + 1;
        }
        else if (list[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            cout << "\n\nThe Target Element Is Found At " << mid << " Index" << endl;
            return mid;
        }
    }

    cout << "\n\nThe Target Element Is Not Found In The List" << endl;
    return -1;
}

int main()
{
    int size;
    cout << "Enter The Size Of The Array : ";
    cin >> size;

    int *Numbers = new int[size];

    cout << "\n\nEnter The Elements Of The Array : " << endl
         << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Element : ";
        cin >> Numbers[i];
    }

    int target;
    cout << "\n\nNow Enter The Element You Want To Search In The List : ";
    cin >> target;

    LinearSearch(Numbers, size, target);

    BinarySearch(Numbers, size, target);
}