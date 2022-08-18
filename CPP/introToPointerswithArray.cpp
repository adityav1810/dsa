#include<iostream>
using namespace std;
int main(){
    int a[20] = {1,2,3,5};
    cout<<&a[0]<<" :  "<<sizeof(&a[0])<<endl;
    cout<<&a<<" :  "<<sizeof(&a)<<endl;
    cout<<a<<" :  "<<sizeof(a)<<endl;
    int *p = &a[0];
    cout<<p<<" :  "<<sizeof(p)<<endl;
    cout<<*p<<" :  "<<sizeof(*p)<<endl;
    cout<<&p<<" :  "<<sizeof(&p)<<endl;



    return 0;
}