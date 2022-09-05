// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int pascalTrianglePnC(int n, int r){
    if(r==0 || n==r){
        return 1;
    }
    return pascalTrianglePnC(n-1,r-1) + pascalTrianglePnC(n-1,r);
    
}

int main() {
    // Write C++ code here
    cout<<pascalTrianglePnC(4,2);

    return 0;
}