#include<iostream>
using namespace std;

int getSum(int *arr,int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum +=arr[i];
    }
    return sum;

}

int main(){
    int n,m;
    cin>>n>>m;
    int **arr = new int *[n];
    for(int i=0;i<n;i++){
        arr[i] = new int [m];
    }



    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];

        }
        
    }
        for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;
        
    }
    cout << endl;

    // cout<<getSum(arr,n)<<endl;



    return 0;
}