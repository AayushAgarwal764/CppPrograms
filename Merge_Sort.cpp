#include<iostream>
using namespace std;

void merge(int* arr, int lowerIndex, int middleIndex, int higherIndex)
{
    int temp[7]{};
    int indexOfSubArrayLeft = lowerIndex;
    int indexOfSubArrayRight = middleIndex+1;
    int indexOfTempArray = lowerIndex;

    while(indexOfSubArrayLeft <= middleIndex && indexOfSubArrayRight <= higherIndex)
    {
        if(arr[indexOfSubArrayLeft] <= arr[indexOfSubArrayRight])
        {
            temp[indexOfTempArray] = arr[indexOfSubArrayLeft];
            ++indexOfSubArrayLeft;
            ++indexOfTempArray;
        }
        else
        {
            temp[indexOfTempArray] = arr[indexOfSubArrayRight];
            ++indexOfSubArrayRight;
            ++indexOfTempArray;
        }
    }

    while(indexOfSubArrayLeft <= middleIndex)
    {
        temp[indexOfTempArray] = arr[indexOfSubArrayLeft];
        ++indexOfSubArrayLeft;
        ++indexOfTempArray;
    }

    while(indexOfSubArrayRight <= higherIndex)
    {
        temp[indexOfTempArray] = arr[indexOfSubArrayRight];
        ++indexOfSubArrayRight;
        ++indexOfTempArray;
    }

    for(int counter = lowerIndex; counter <=  higherIndex; ++counter)
    {
        arr[counter] = temp[counter];
    }


}

void mergeSort(int* arr, int lowerIndex, int higherIndex)
{
    if(lowerIndex < higherIndex)
    {
        int middleIndex = (lowerIndex + higherIndex) / 2;
        mergeSort(arr, lowerIndex, middleIndex);
        mergeSort(arr, middleIndex+1, higherIndex);
        merge(arr, lowerIndex, middleIndex, higherIndex);
    }

}
int main()
{
    int arr[7]{7,6,2,3,4,5,1};
    cout << "Before Sorting\n";
    for(int element:arr)
    {
        cout << element << " ";
    }

    mergeSort(arr, 0, 6);

    cout << "\nAfter Sorting\n";
    for(int element:arr)
    {
        cout << element << " ";
    }
    cout << "\n";
    return 0;
}