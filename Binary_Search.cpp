
#include<iostream>
using namespace std;

void binarySearch(int* arr, int lowerIndex, int higherIndex, int searchTerm)
{
    
    int indexOfMiddleTerm{};
    indexOfMiddleTerm = (lowerIndex + higherIndex) / 2;
    if(higherIndex < lowerIndex)
    {
        cout << "Element Not Found\n";
        return;
    }
    if(arr[indexOfMiddleTerm] == searchTerm)
    {
        cout << "Search Term " << searchTerm << " found at Index " << indexOfMiddleTerm << "\n";
    }
    if(arr[indexOfMiddleTerm] > searchTerm)
    {
        binarySearch(arr, lowerIndex, indexOfMiddleTerm-1, searchTerm);
    }
    if(arr[indexOfMiddleTerm] < searchTerm)
    {
        binarySearch(arr, indexOfMiddleTerm+1, higherIndex, searchTerm);
    }
}

int main()
{
    int arr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int searchTerm{};
    cout << "Enter Term to Search :";
    cin >> searchTerm;
    binarySearch(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1, searchTerm);
    return 0;
}