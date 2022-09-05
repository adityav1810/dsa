#include<iostream>
using namespace std;
void update(int &n){
    n++;

}
void printArray(int arr[],int n){
    cout<<arr<<endl;

    for(int i =0;i<n;i++){

cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int* updateArray(int arr[],int n){
    for(int i =0;i<n;i++){
        arr[i]++;

    }
    return arr;
}
int * updatePointerarr(int *arr,int n){
    for(int i = 0; i<n;i++){
        *(arr+i) = *(arr+i) + 1;
        
    }
    cout<<endl;
    return arr;
}
int main(){
    int n =5;
    cout<<n<<endl;
    update(n);
    cout<<n<<endl;
    int arr[5] = {1,2,3,4,5};
    cout<<arr<<endl;
    printArray(arr,5);
    
    printArray(updateArray(arr,5),5);
    printArray(updatePointerarr(arr,5),5);

    return 0;
    

}