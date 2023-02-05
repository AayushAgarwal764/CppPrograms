#include<iostream>
using namespace std;

void swapValues(int& val1, int& val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void insertion_sort(int* arr, int sizeOfArray)
{
    int i{}, j{};
    for(i = 1; i < sizeOfArray; i++)
    {
        int& key = arr[i];

        for(j = 0; j < i; j++)
        {
            if(key < arr[j])
            {
                swapValues(key, arr[j]);
            }
        }
    }
}
void printArray(int* arr, int sizeOfArray)
{
    int i{};
    for(i = 0; i < sizeOfArray; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int arr[5]{4, 5, 8, 3, 9};
    printArray(arr, 5);
    insertion_sort(arr, 5);
    printArray(arr, 5);
    return 0;
}