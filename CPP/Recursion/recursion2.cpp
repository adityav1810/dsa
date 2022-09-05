#include<iostream>
using namespace std;
bool isSortedArray(int arr[],int n){
    /*
    Function to find if Array is sorted or not
    using Recursion
    */

//  Base Case
if (n <=1){
    return true;

}
if(arr[0]>arr[1]){
    return false;
}
else if(arr[0]<=arr[1]){
    return true;
}
else{

// Recursive Function
    return isSortedArray(arr+1,n-1);
}

}


int getSum(int arr[],int size){

    /*
    Function to calculate sum of array
    using Recursion
    */

// Base Case
if (size ==0){
    return 0;
}

if (size==1){
return arr[0];
}
    // Recursive Relation
    return arr[0]+getSum(arr+1,size-1) ;
}

bool linearSearch(int *arr,int size,int key){
/*
Function to find given element using Linear Search
using Recursion
*/

// Base Class
if (size ==0){
    return false;
}
if(arr[0] == key){
    return true;
}


return linearSearch(arr+1,size-1,key);


}




int main(){
    // int arr[5] = {3,2,6,1,9};
    int arr[5] = {1,2,3,4,5};
    cout<<isSortedArray(arr,5)<<endl;
    cout<<getSum(arr,5)<<endl;
    cout<<linearSearch(arr,5,3)<<endl;

    
    return 0;

}