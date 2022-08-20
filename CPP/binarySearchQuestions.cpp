#include <iostream>

using namespace std;

int getFirstOccurance(int *arr, int left, int right, int key)
{
    // Function returns first occurance of key in array

    // array length sanity check
    if (left <= right)
    {
        // calcualte mid for recourance
        int mid = left + (right - left) / 2;
        // if mid element is key, return mid index
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            // if arr[mid] is greater than key, check left side of array
            getFirstOccurance(arr, left, mid - 1, key);
        }
        // if arr[mid] is Less than key, check RiGHT side of array
        getFirstOccurance(arr, mid + 1, right, key);
    }

    // element not found
    return -1;
}

int main()
{
    int arr[6] = {1,2,3,3,3,5};
    int size = 6;
    int key = 3;

    int start = getFirstOccurance(arr, 0, size, key);
    if (start ==-1){
        cout<<start<<" "<<start<<endl;
        return 0;
    }


    int end = start;

    for(int i = start;i<size;i++){
        if(arr[i] == key){
            ++end ;
        }
    }

    
    cout <<end - start + 1<< endl;

    return 0;
}