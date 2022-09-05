#include <iostream>
using namespace std;

int binarySearch(int *arr, int low, int high, int key)
{
    /*
    Function to find element in sorted array, Binary Search
    Iterative Method
    */
    high = high - 1;
    while (low <= high)
    {

        int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchRec(int *arr, int low, int high, int key)
{
    /*
    Binary Search using Recursive Implementation
    */
    if (high >= low)
    {
        //    Base case
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] > key)
        {
            return binarySearchRec(arr, low, mid - 1, key);
        }
        
            return binarySearchRec(arr, mid + 1, high, key);
        
    }
    return -1;
}

int main()
{
    int arr[5] = {6, 7, 8, 9, 10};
    int key = 9;

    cout << binarySearch(arr, 0, 5, key);
    cout << binarySearchRec(arr, 0, 5, key);
    return 0;
}