#include <iostream>
using namespace std;
class TwoStack
{
    int *arr;
    int size;
    int top1;
    int top2;

public:
    TwoStack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }
    void push1(int data)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "Stack 1 Overflow" << endl;
        }
    }
    void push2(int data)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = data;
        }
        else
        {
            cout << "Stack 2 Overflow" << endl;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return top1;
        }
        else
        {
            cout << "Stack 1 Underflow" << endl;
            return -1;
        }
    }
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            cout << "Stack 2 underflow" << endl;
            return -1;
        }
    }
    void peak1()
    {
        cout << arr[top1] << endl;
    }
    void peak2()
    {
        cout << arr[top2] << endl;
    }
};

int main()
{
    TwoStack tst(6);
    tst.push1(10);
    tst.push1(12);

    tst.push2(12);
    tst.push2(4);
    tst.push2(1);

    tst.peak1();
    tst.peak2();
    tst.pop1();
    tst.pop2();
    tst.peak1();
    tst.peak2();

    return 0;
}