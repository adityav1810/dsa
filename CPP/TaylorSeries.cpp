// Online C++ compiler to run C++ program online
#include <iostream>
#include<cmath>
using namespace std;
float factorial(float num){

    if (num <=1){
        return 1;
    }
    return num * factorial(num-1);
}

float taylorseries(float x ,float n){
    /*
    Taylor series Recursive Function
    e^x = 1 + x^1/1! + x^2/2! + x^3 / 3! + ... + n terms
    
    */
    
    // base case  = n = 0
    if (n==0){
        return 1;
    }
    float nterm = pow(x,n) / factorial(n);
    return taylorseries(x,n-1) + nterm;
    
    
}

int main() {
    // Write C++ code here
    cout<<taylorseries(2,3);

    return 0;
}