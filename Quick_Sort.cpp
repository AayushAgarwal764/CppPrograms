#include<iostream>
using namespace std;


void swapElements(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* arr, int startingIndex, int endingIndex)
{
    int pIndex{0};
    int pivot = arr[endingIndex];
    for(int i = 0; i < endingIndex; ++i)
    {
        if(arr[i] < pivot)
        {
            swapElements(arr[i], arr[pIndex]);
            ++pIndex;
        }
    }
    swapElements(arr[pIndex], arr[endingIndex]);
    return pIndex;
}

void quickSort(int* arr, int lowerIndex, int higherIndex)
{
    if(lowerIndex < higherIndex)
    {
        int p = partition(arr, lowerIndex, higherIndex);

        quickSort(arr, lowerIndex, p-1);
        quickSort(arr, p+1, higherIndex);
    }
}

int main()
{
    int arr[7]{2,3,6,5,7,1,4};
    cout << "Before Sorting:\n";
    for(int element : arr)
    {
        cout << element << " ";
    }
    quickSort(arr, 0, 6);

    cout << "\nAfter Sorting\n";
    for(int element : arr)
    {
        cout << element << " ";
    }
    cout << "\n";

    return 0;
}