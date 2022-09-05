#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> &arr, int left, int right)
{
    // Trying recursive method but some cases fail for eg {4 10 5 2}
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        cout << "arr[mid] is : " << mid << endl;

        // peak
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            cout << mid;
            return mid;
        }
        else if (arr[mid - 1] > arr[mid] && arr[mid] < arr[mid + 1])
        {
            // cout<<mid;
            findPeak(arr, mid + 1, right);
        }
        // cout<<mid;
        findPeak(arr, left, mid - 1);
    }
    return -1;
}

int findPeak(vector<int>& arr,int start,int end){

    
    while(start < end)
    {
        int mid = ((end - start)/2) + start;
        
        if(arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    
    return start;
}



int main()
{
    vector<int> vect{4, 6, 9, 11, 45, 40, 20, 1};
    cout << findPeak(vect, 0,vect.size() ) << endl;

    return 0;
}