#include<iostream>
using namespace std;

void BubbleSort(int* arr)
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = i+1; j < 5; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int arr[5]{3, 4, 9, 8, 2};
    cout << "Sorted List using Bubble Sort:\n";
    BubbleSort(arr);
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}