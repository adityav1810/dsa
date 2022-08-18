#include<iostream>
using namespace std;
void updatePointer(int *p){
    *p = *p+1;
    

}
int getSum(int arr[],int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum = sum+ arr[i];
    }
    return sum;
}
int main(){
    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";
    cout<<arr<<endl;
    cout<<ch<<endl;
    cout<<*ch<<endl;
    cout<<&ch<<endl;

    int value = 5;
    int *p = &value;
    cout<<value;
    updatePointer(p);
    cout<<value;

    int arr[5]={1,2,3,4,5};
    cout<<getSum(arr+3,2)<<endl;
    
    return 0;



}