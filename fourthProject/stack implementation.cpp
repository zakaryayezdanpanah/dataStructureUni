#include <iostream>

using namespace std;

class stack
{
private:
    int stack[10], maxSize = 10, top = -1;

public:
    bool isEmpty();
    bool isFull();
    void push(int);
    int pop();
    int peek();
};

bool stack::isEmpty()
{
    if (this->top == -1)
        return true;
    else
        return false;
}

bool stack::isFull()
{
    if (this->top == this->maxSize - 1)
        return true;
    else
        return false;
}

void stack::push(int value)
{
    if (isFull())
        return;

    this->stack[++this->top] = value;
}

int stack::pop()
{
    if (isEmpty())
        return 0;

    return this->stack[this->top--];
}

int stack::peek()
{
    if (isEmpty())
        return 0;
    return this->stack[this->top];
}