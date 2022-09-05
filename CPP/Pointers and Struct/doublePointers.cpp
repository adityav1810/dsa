#include<iostream>
using namespace std;
void update(int **p){
    **p = **p+1;
}


int main(){
    // int i = 5;
    // int *ptr = &i;
    // int **ptr2 = &ptr;

    // cout<<&i<<endl;
    // cout<<&ptr<<endl;

    // cout<<&ptr2<<endl;
    // cout<<*ptr<<endl;
    // cout<<*&ptr<<endl;
    // update(ptr2);
    // cout<<i<<endl;
    int f = 6;
    int *p = &f;
    int *q = p;
    cout<<*q<<endl;
    (*q)++;
    cout<<*q<<endl;
    cout<<f<<endl;



    
    return 0;

}