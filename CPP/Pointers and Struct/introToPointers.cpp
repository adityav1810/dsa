#include<iostream>
using namespace std;
int main(){
    int num = 5;
    cout<<"Address of num :"<<&num<<endl;
    cout<<"Value stored inside of num"<<num<<endl;
    int *ptr = &num;
    cout<<"Value stored inside of ptr"<<ptr<<endl;
    cout<<"ptr points to : "<<*ptr<<endl;
    
    

    return 0;
}