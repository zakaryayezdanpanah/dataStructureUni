#include <iostream>
#include <stack>

using namespace std;

class queue
{

private:
    stack<int> mainStack;
    stack<int> subStack;

public:
    void enqueue(int);
    int dequeue();
};

void queue ::enqueue(int value)
{
    while (!mainStack.empty())
    {
        subStack.push(mainStack.top());
        mainStack.pop();
    }

    mainStack.push(value);

    while (!subStack.empty())
    {
        mainStack.push(subStack.top());
        subStack.pop();
    }
}

int queue ::dequeue()
{
    if (mainStack.empty())
    {
        return 0;
    }
    else
    {
        int top = mainStack.top();
        mainStack.pop();
        return top;
    }
}