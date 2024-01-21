#include "./simple Linked List.cpp"

class stack
{
private:
    linkedList stack;
    int maxSize = 100;
    int counter = 0;

public:
    bool isEmpty();
    bool isFull();
    void push(int);
    void showItems();
    int pop();
};

bool stack::isEmpty()
{
    if (this->counter == 0)
        return true;
    else
        return false;
}

bool stack::isFull()
{
    if (this->counter == this->maxSize - 1)
        return true;
    else
        return false;
}

void stack::push(int value)
{
    if (isFull())
        return;

    this->stack.insertAtEnd(value);
    this->counter++;
}

void stack::showItems()
{
    stack.showAllItems();
}

int stack::pop()
{
    if (isEmpty())
        return 0;

    this->counter--;
    return this->stack.removeNodeAtEnd();
}