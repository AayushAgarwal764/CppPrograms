#include<iostream>
using namespace std;

void linearSearch(int* arr, int sizeOfArray, int searchTerm)
{
    int i{};
    for(i = 0; i < sizeOfArray; ++i)
    {
        if(arr[i] == searchTerm)
        {
            cout << "Search Term " << searchTerm << " found at Index " << i << "\n";
            return;
        }

    }
    cout << "Serch Term Not Found\n";
    
}


int main()
{
    int arr[10]{1,2,3,4,5,6,7,8,9,0};
    int searchTerm{};
    cout << "Enter Term to Search :";
    cin >> searchTerm;

    linearSearch(arr, sizeof(arr)/sizeof(arr[0]), searchTerm);
    return 0;
}