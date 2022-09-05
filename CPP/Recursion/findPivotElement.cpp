#include<iostream>
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


int main(){

cout<<"Hello World";    
    return 0;
}