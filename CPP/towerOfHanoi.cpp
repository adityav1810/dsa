#include<iostream>
using namespace std;


int TOH(int n, int a,int b, int c){
    if (n>0){
        TOH(n-1,a,c,b);
        cout<<"FROM "<<a <<" TO "<<c<<endl;
        TOH(n-1,b,a,c);
    }

}

int main(){
    cout<<TOH(3,1,2,3);
    return 0;
}