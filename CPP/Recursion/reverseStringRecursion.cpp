#include<iostream>
#include<string>

using namespace std;

void printString(string &name,int i,int j){
    

    if(i>j){
        return;
    }
    swap(name[i],name[j]);
    i++;
    j--;

    printString(name,i,j);

    
}



int main(){
    string name ="aditya";

    printString(name,0,name.length()-1);
    cout<<name;
    return 0;
}
