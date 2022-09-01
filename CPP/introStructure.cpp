#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Student
{
    int rollno;
    char name[10];
};


int main()
{
    struct Student a = {1, "Karen"};
    
    // Another way to initialise a structure using pointers
    Student *b = new Student;
    cout << a.rollno << " " << a.name << sizeof(a.rollno) << sizeof(a.name) << " " << sizeof(a) << endl;




    return 0;
}