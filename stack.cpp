#include<iostream>
#define max 15
using namespace std;

template<class type>
class Stack
{
private:
    type data[max];
    int top;
public:
    Stack();
    int isempty();
    void push(type);
    type pop(void);
    type Top();
};

template<class type>
Stack<type>::Stack()
{
    this->top = -1;
}
template<class type>
int Stack<type>::isempty()
{
    if(this->top==-1)
    {
        return 1;
    }
    return 0;
}
template<class type>
void Stack<type>::push(type d)
{
    if(this->top == max+1)
    {
        cout<<"Overflow\n";
        return;
    }
    this->top++;
    this->data[this->top] = d;
}
template<class type>
type Stack<type>::pop()
{
    if(isempty())
    {
        cout<<"Underflow\n";
        return -1;
    }
    type d = this->data[this->top];
    this->top--;
    return d;
}
template<class type>
type Stack<type>::Top()
{
    return this->data[this->top];
}

int main()
{
    Stack<long> s;
    int d;
    for(int i=1;i<=14;i++)
        s.push(i);
    for(int j=1;j<=16;j++)
        cout<<s.pop()<<" ";
}
