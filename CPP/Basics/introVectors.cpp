// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int main() {
    // Write C++ code here
    
    vector<vector<int>> a
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
cout<<&a<<endl;

for(int i = 0;i<3;i++){
    for(int j = 0; j<3;j++){
        cout<<&a[i][j]<<" ";
    }
    cout<<endl;
}


    return 0;
}